<?php

namespace GeoIP2\Model;

/**
 * @ignore
 */
abstract class AbstractModel implements \JsonSerializable
{

    protected $attr;


    protected $raw;


    /**
     * @ignore
     *
     * @param mixed $raw
     * @param mixed $$raw
     */
    public function __construct($raw) {}

    /**
     * @ignore
     *
     * @param string $field
     * @param mixed $$field
     */
    protected function get($field) {}

    /**
     * @ignore
     *
     * @param mixed $attr
     * @param mixed $$attr
     */
    public function __get($attr) {}

    /**
     * @ignore
     *
     * @param mixed $attr
     * @param mixed $$attr
     */
    public function __isset($attr) {}


    public function jsonSerialize() {}

    /**
     * @param int $options
     */
    public function json($options = 0) {}

}
