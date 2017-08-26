<?php

namespace GeoIP2\Record;


abstract class AbstractRecord implements \JsonSerializable
{

    protected $validAttributes;


    protected $record = array();


    /**
     * @ignore
     *
     * @param mixed $record
     * @param mixed $$record
     */
    public function __construct($record) {}

    /**
     * @ignore
     *
     * @param string $attr
     * @param mixed $$attr
     */
    public function __get($attr) {}

    /**
     * @param string $name
     */
    public function getName($name) {}

    /**
     * @param string $attr
     */
    public function __isset($attr) {}

    /**
     * @param string $attr
     */
    private function attributeToKey($attr) {}

    /**
     * @param string $attr
     */
    private function validAttribute($attr) {}


    public function jsonSerialize() {}

    /**
     * @param int $options
     */
    public function json($options = 0) {}

}
