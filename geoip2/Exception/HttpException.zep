namespace GeoIP2\Exception;

/**
 * This class represents a generic error.
 */
class HttpException extends GeoIP2Exception
{
    /**
     *  This class represents an HTTP transport error.
     */
    public uri;

    public function __construct(string message, int httpStatus, string uri, object previous) {
        let this->uri = uri;
        parent::__construct(message, httpStatus, previous);
    }
}