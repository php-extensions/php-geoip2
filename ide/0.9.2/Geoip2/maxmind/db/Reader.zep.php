<?php

namespace GeoIP2\MaxMind\Db;

/**
 * Instances of this class provide a reader for the MaxMind DB format. IP
 * addresses can be looked up using the get method.
 */
class Reader
{

    static private $data_section_separator_size = 16;


    static private $metadata_start_marker;


    static private $metadata_start_marker_length = 14;


    static private $metadata_max_size = 131072;


    private $decoder;


    private $fileHandle;


    private $fileSize;


    private $ipV4Start;


    private $metadata;


    /**
     * Constructs a Reader for the MaxMind DB format. The file passed to it must
     * be a valid MaxMind DB file such as a GeoIp2 database file.
     *
     * @param string database
     *                         the MaxMind DB file to use
     *
     * @throws \InvalidArgumentException                   for invalid database path or unknown arguments
     * @throws \MaxMind\Db\Reader\InvalidDatabaseException
     *                                                     if the database is invalid or there is an error reading
     *                                                     from it
     * @param string $database
     */
    public function __construct(string $database) {}

    /**
     * Looks up the address in the MaxMind DB.
     *
     * @param string ipAddress
     *                          the IP address to look up
     *
     * @throws \BadMethodCallException   if this method is called on a closed database
     * @throws \InvalidArgumentException if something other than a single IP address is passed to the method
     * @throws InvalidDatabaseException
     *                                   if the database is invalid or there is an error reading
     *                                   from it
     *
     * @param mixed $ipAddress
     * @return array record for the IP address
     */
    public function get($ipAddress) {}

    /**
     * @param mixed $ipAddress
     */
    private function findAddressInTree($ipAddress) {}

    /**
     * @param mixed $length
     */
    private function startNode($length) {}


    private function ipV4StartNode() {}

    /**
     * @param mixed $nodeNumber
     * @param mixed $index
     */
    private function readNode($nodeNumber, $index) {}

    /**
     * @param mixed $pointer
     */
    private function resolveDataPointer($pointer) {}

    /**
     * @param mixed $filename
     */
    private function findMetadataStart($filename) {}

    /**
     * @throws \InvalidArgumentException if arguments are passed to the method
     * @throws \BadMethodCallException   if the database has been closed
     *
     * @return Metadata for the database
     */
    public function metadata() {}

    /**
     * Closes the MaxMind DB and returns resources to the system.
     *
     * @throws \Exception
     *                    if an I/O error occurs
     */
    public function close() {}

}
