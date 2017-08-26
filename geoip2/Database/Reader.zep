namespace GeoIP2\Database;

use GeoIP2\Exception\AddressNotFoundException;
use GeoIP2\Exception\InvalidDatabaseException;
use GeoIP2\ProviderInterface;
use GeoIP2\Database\Reader\Metadata;
use MaxMind\Db\Reader as DbReader;

class Reader implements ProviderInterface
{
    private dbReader;
    private locales;

    private metadata;

    /**
     * Constructor.
     *
     * @param string $filename the path to the GeoIP2 database file
     * @param array  $locales  list of locale codes to use in name property
     *                         from most preferred to least preferred
     *
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     */
    public function __construct(string filename, var locales = "") {
        let this->dbReader = <MaxMind\Db\Reader> new DbReader(filename);
        if typeof locales == "array" {
            let this->locales = locales;
        } elseif typeof locales == "string" {
            let this->locales = [locales];
        }
    }

    /**
     * This method returns a GeoIP2 City model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\City
     */
    public function city(string ipAddress)
    {
        return this->modelFor("City", "City", ipAddress);
    }
    /**
     * This method returns a GeoIP2 Country model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\Country
     */
    public function country(string ipAddress)
    {
        return this->modelFor("Country", "Country", ipAddress);
    }
    /**
     * This method returns a GeoIP2 Anonymous IP model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\AnonymousIp
     */
    public function anonymousIp(string ipAddress)
    {
        return this->flatModelFor(
            "AnonymousIp",
            "GeoIP2-Anonymous-IP",
            ipAddress
        );
    }
    /**
     * This method returns a GeoLite2 ASN model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\Asn
     */
    public function asn(string ipAddress)
    {
        return this->flatModelFor(
            "Asn",
            "GeoLite2-ASN",
            ipAddress
        );
    }
    /**
     * This method returns a GeoIP2 Connection Type model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\ConnectionType
     */
    public function connectionType(string ipAddress)
    {
        return this->flatModelFor(
            "ConnectionType",
            "GeoIP2-Connection-Type",
            ipAddress
        );
    }
    /**
     * This method returns a GeoIP2 Domain model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\Domain
     */
    public function domain(string ipAddress)
    {
        return this->flatModelFor(
            "Domain",
            "GeoIP2-Domain",
            ipAddress
        );
    }
    /**
     * This method returns a GeoIP2 Enterprise model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\Enterprise
     */
    public function enterprise(string ipAddress)
    {
        return this->modelFor("Enterprise", "Enterprise", ipAddress);
    }
    /**
     * This method returns a GeoIP2 ISP model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @return \GeoIP2\Model\Isp
     */
    public function isp(string ipAddress)
    {
        return this->flatModelFor(
            "Isp",
            "GeoIP2-ISP",
            ipAddress
        );
    }
    private function modelFor(string className, string type, string ipAddress)
    {
        var record;
        let record = this->getRecord(className, type, ipAddress);
        let record["traits"]["ip_address"] = ipAddress;
        let className = "GeoIP2\\Model\\" . className;
        return new {className}(record, this->locales);
    }
    private function flatModelFor(string className, string type, string ipAddress)
    {
        var record;
        let record = this->getRecord(className, type, ipAddress);
        let record["ip_address"] = ipAddress;
        let className = "GeoIP2\\Model\\" . className;
        return new {className}(record);
    }
    private function getRecord(string className, string type, string ipAddress)
    {
        var record;
        let record = this->dbReader->get(ipAddress);
        if (record === null) {
            throw new AddressNotFoundException(
                "The address ". ipAddress . " is not in the database."
            );
        }
        if typeof record != "array" {
            // This can happen on corrupt databases. Generally,
            // MaxMind\Db\Reader will throw a
            // MaxMind\Db\Reader\InvalidDatabaseException, but occasionally
            // the lookup may result in a record that looks valid but is not
            // an array. This mostly happens when the user is ignoring all
            // exceptions and the more frequent InvalidDatabaseException
            // exceptions go unnoticed.
            throw new InvalidDatabaseException(
                "Expected an array when looking up ". ipAddress . " but received: "
                . typeof record
            );
        }
        return record;
    }

    /**
     * @return \GeoIP2\Database\Reader\Metadata object for the database
     */
    public function metadata()
    {
        if empty this->metadata {
            var md = [
                "binary_format_major_version": "",
                "binary_format_minor_version": "",
                "build_epoch": "",
                "database_type": "",
                "languages": "",
                "description": "",
                "ip_version": "",
                "node_count": 0,
                "record_size": 0
            ];
            var record = this->dbReader->get("128.101.101.101");
            if isset record["city"]["names"] {
                let md["database_type"] = "GeoIP2-City";
            } elseif isset record["country"]["names"] {
                let md["database_type"] = "GeoIP2-Country";
            }
            let this->metadata = new Metadata(md);
        }
        return this->metadata;
    }

    /**
     * Closes the GeoIP2 database and returns the resources to the system.
     */
    public function close()
    {
        this->dbReader->close();
    }
}