namespace GeoIP2\Record;

abstract class AbstractRecord implements \JsonSerializable
{
    protected validAttributes;

    protected record = [];
    /**
     * @ignore
     *
     * @param mixed $record
     */
    public function __construct(var record)
    {
        if !empty record {
            let this->record = record;
        }
    }
    /**
     * @ignore
     *
     * @param mixed $attr
     */
    public function __get(string attr)
    {
        var key;
        let key = this->attributeToKey(attr);
        if this->__isset(attr) {
            return this->record[key];
        } elseif this->validAttribute(attr) {
            if (preg_match("/^is_/", key)) {
                return false;
            }
            return null;
        }
        throw new \RuntimeException("Unknown attribute: " . attr);
    }
    public function getName(string name)
    {
        if isset this->record["names"][name] {
            return this->record["names"][name];
        }
        return null;
    }

    public function __isset(string attr)
    {
        return this->validAttribute(attr) &&
             isset this->record[this->attributeToKey(attr)];
    }
    private function attributeToKey(string attr)
    {
        var v;
        let v = preg_replace("/([A-Z])/", "_\1", attr);
        return strtolower(v);
    }
    private function validAttribute(string attr)
    {
        return in_array(attr, this->validAttributes, true);
    }
    public function jsonSerialize()
    {
        return this->record;
    }
    public function json(int options = 0)
    {
        return json_encode(this, options);
    }
}