<?php

namespace GeoIP2\Database;


class Reader implements \GeoIP2\ProviderInterface
{

    private $dbReader;


    private $locales;


    private $metadata;


    /**
     * Constructor.
     *
     * @param array  $locales  list of locale codes to use in name property
     *                         from most preferred to least preferred
     *
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     * @param string $filename the path to the GeoIP2 database file
     * @param mixed $locales
     */
    public function __construct(string $filename, $locales = '') {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\City
     */
    public function city(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\Country
     */
    public function country(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\AnonymousIp
     */
    public function anonymousIp(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\Asn
     */
    public function asn(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\ConnectionType
     */
    public function connectionType(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\Domain
     */
    public function domain(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\Enterprise
     */
    public function enterprise(string $ipAddress) {}

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
     * @param string $ipAddress
     * @return \GeoIP2\Model\Isp
     */
    public function isp(string $ipAddress) {}

    /**
     * @param string $className
     * @param string $type
     * @param string $ipAddress
     */
    private function modelFor(string $className, string $type, string $ipAddress) {}

    /**
     * @param string $className
     * @param string $type
     * @param string $ipAddress
     */
    private function flatModelFor(string $className, string $type, string $ipAddress) {}

    /**
     * @param string $className
     * @param string $type
     * @param string $ipAddress
     */
    private function getRecord(string $className, string $type, string $ipAddress) {}

    /**
     * @throws \InvalidArgumentException if arguments are passed to the method
     * @throws \BadMethodCallException   if the database has been closed
     *
     * @return \GeoIP2\MaxMind\Db\Reader\Metadata for the database
     */
    public function metadata() {}

    /**
     * Closes the GeoIP2 database and returns the resources to the system.
     */
    public function close() {}

}
