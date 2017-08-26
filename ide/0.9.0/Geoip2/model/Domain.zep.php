<?php

namespace GeoIP2\Model;

/**
 * This class provides the GeoIP2 Domain model.
 *
 * @property-read string|null domain The second level domain associated with the
 *     IP address. This will be something like "example.com" or
 *     "example.co.uk", not "foo.example.com".
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
class Domain extends \GeoIP2\Model\AbstractModel
{

    protected $domain;


    protected $ipAddress;


    /**
     * @ignore
     *
     * @param mixed $raw
     */
    public function __construct($raw) {}

}
