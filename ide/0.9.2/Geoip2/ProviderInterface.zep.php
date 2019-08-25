<?php

namespace GeoIP2;


interface ProviderInterface
{

    /**
     * @param string $ipAddress an IPv4 or IPv6 address to lookup
     *
     * @param string $ipAddress
     * @return \GeoIp2\Model\Country Country model for the requested IP address
     */
    public function country(string $ipAddress);

    /**
     * @param string $ipAddress an IPv4 or IPv6 address to lookup
     *
     * @param string $ipAddress
     * @return \GeoIp2\Model\City City model for the requested IP address
     */
    public function city(string $ipAddress);

}
