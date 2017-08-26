<?php

namespace GeoIP2\Database;


class Reader implements \GeoIP2\ProviderInterface
{

    private $dbReader;


    private $locales;


    /**
     * Constructor.
     *
     * @param array  $locales  list of locale codes to use in name property
     *                         from most preferred to least preferred
     *
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     * @param string $filename
     * @param mixed $locales
     * @param string $$filename the path to the GeoIP2 database file
     */
    public function __construct($filename, $locales = "") {}

    /**
     * This method returns a GeoIP2 City model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\City
     */
    public function city($ipAddress) {}

    /**
     * This method returns a GeoIP2 Country model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\Country
     */
    public function country($ipAddress) {}

    /**
     * This method returns a GeoIP2 Anonymous IP model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\AnonymousIp
     */
    public function anonymousIp($ipAddress) {}

    /**
     * This method returns a GeoLite2 ASN model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\Asn
     */
    public function asn($ipAddress) {}

    /**
     * This method returns a GeoIP2 Connection Type model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\ConnectionType
     */
    public function connectionType($ipAddress) {}

    /**
     * This method returns a GeoIP2 Domain model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\Domain
     */
    public function domain($ipAddress) {}

    /**
     * This method returns a GeoIP2 Enterprise model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\Enterprise
     */
    public function enterprise($ipAddress) {}

    /**
     * This method returns a GeoIP2 ISP model.
     *
     * @param string $ipAddress an IPv4 or IPv6 address as a string
     *
     * @throws \GeoIP2\Exception\AddressNotFoundException  if the address is
     *                                                     not in the database
     * @throws \GeoIP2\Exception\InvalidDatabaseException  if the database
     *                                                     is corrupt or invalid
     *
     * @param string $ipAddress
     * @return \GeoIP2\Model\Isp
     */
    public function isp($ipAddress) {}

    /**
     * @param string $className
     * @param string $type
     * @param string $ipAddress
     */
    private function modelFor($className, $type, $ipAddress) {}

    /**
     * @param string $className
     * @param string $type
     * @param string $ipAddress
     */
    private function flatModelFor($className, $type, $ipAddress) {}

    /**
     * @param string $className
     * @param string $type
     * @param string $ipAddress
     */
    private function getRecord($className, $type, $ipAddress) {}

    /**
     * Closes the GeoIP2 database and returns the resources to the system.
     */
    public function close() {}

}
