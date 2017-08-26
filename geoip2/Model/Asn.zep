namespace GeoIP2\Model;
/**
 * This class provides the GeoLite2 ASN model.
 *
 * @property-read int|null autonomousSystemNumber The autonomous system number
 *     associated with the IP address.
 * @property-read string|null autonomousSystemOrganization The organization
 *     associated with the registered autonomous system number for the IP
 *     address.
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
class Asn extends AbstractModel
{
    protected autonomousSystemNumber;
    protected autonomousSystemOrganization;
    protected ipAddress;
    /**
     * @ignore
     *
     * @param mixed raw
     */
    public function __construct(var raw)
    {
        parent::__construct(raw);
        let this->autonomousSystemNumber = this->get("autonomous_system_number");
        let this->autonomousSystemOrganization =
            this->get("autonomous_system_organization");
        let this->ipAddress = this->get("ip_address");
    }
}