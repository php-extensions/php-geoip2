<?php

namespace GeoIP2\Model;

/**
 * This class provides the GeoIP2 ISP model.
 *
 * @property-read int|null autonomousSystemNumber The autonomous system number
 *     associated with the IP address.
 * @property-read string|null autonomousSystemOrganization The organization
 *     associated with the registered autonomous system number for the IP
 *     address.
 * @property-read string|null isp The name of the ISP associated with the IP
 *     address.
 * @property-read string|null organization The name of the organization associated
 *     with the IP address.
 * @property-read string ipAddress The IP address that the data in the model is
 *     for.
 */
class Isp extends \GeoIP2\Model\AbstractModel
{

    protected $autonomousSystemNumber;


    protected $autonomousSystemOrganization;


    protected $isp;


    protected $organization;


    protected $ipAddress;


    /**
     * @ignore
     *
     * @param mixed $raw
     */
    public function __construct($raw) {}

}
