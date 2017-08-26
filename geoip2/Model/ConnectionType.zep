namespace GeoIP2\Model;
/**
 * This class provides the GeoIP2 Connection-Type model.
 *
 * @property-read string|null connectionType The connection type may take the
 *     following values: "Dialup", "Cable/DSL", "Corporate", "Cellular".
 *     Additional values may be added in the future.
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
class ConnectionType extends AbstractModel
{
    protected connectionType;
    protected ipAddress;
    /**
     * @ignore
     *
     * @param mixed raw
     */
    public function __construct(var raw)
    {
        parent::__construct(raw);
        let this->connectionType = this->get("connection_type");
        let this->ipAddress = this->get("ip_address");
    }
}