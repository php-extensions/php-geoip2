<?php

namespace GeoIP2\Exception;

/**
 * This class represents an error returned by MaxMind's GeoIP2
 * web service.
 */
class InvalidRequestException extends \GeoIP2\Exception\HttpException
{
    /**
     * The code returned by the MaxMind web service.
     */
    public $error;


    /**
     * @param string $message
     * @param string $error
     * @param int $httpStatus
     * @param string $uri
     * @param object $previous
     */
    public function __construct($message, $error, $httpStatus, $uri, $previous) {}

}
