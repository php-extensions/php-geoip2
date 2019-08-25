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
     */
    public function __construct($raw) {}

    /**
     * @ignore
     *
     * @param mixed $field
     */
    protected function get(string $field) {}

    /**
     * @ignore
     *
     * @param mixed $attr
     */
    public function __get(string $attr) {}

    /**
     * @ignore
     *
     * @param mixed $attr
     */
    public function __isset(string $attr) {}


    public function jsonSerialize() {}

    /**
     * @param int $options
     */
    public function json(int $options = 0) {}

}
