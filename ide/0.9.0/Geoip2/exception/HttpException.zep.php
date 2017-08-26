<?php

namespace GeoIP2\Exception;

/**
 * This class represents a generic error.
 */
class HttpException extends \GeoIP2\Exception\GeoIP2Exception
{
    /**
     *  This class represents an HTTP transport error.
     */
    public $uri;


    /**
     * @param string $message
     * @param int $httpStatus
     * @param string $uri
     * @param object $previous
     */
    public function __construct($message, $httpStatus, $uri, $previous) {}

}
