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
     */
    public function __construct($record) {}

    /**
     * @ignore
     *
     * @param mixed $attr
     */
    public function __get(string $attr) {}

    /**
     * @param string $name
     */
    public function getName(string $name) {}

    /**
     * @param string $attr
     */
    public function __isset(string $attr) {}

    /**
     * @param string $attr
     */
    private function attributeToKey(string $attr) {}

    /**
     * @param string $attr
     */
    private function validAttribute(string $attr) {}


    public function jsonSerialize() {}

    /**
     * @param int $options
     */
    public function json(int $options = 0) {}

}
