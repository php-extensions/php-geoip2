namespace GeoIP2\Exception;

/**
 * This class represents an error returned by MaxMind's GeoIP2
 * web service.
 */
class InvalidRequestException extends HttpException
{
    /**
     * The code returned by the MaxMind web service.
     */
    public error;

    public function __construct(string message, string error, int httpStatus, string uri, object previous) {
        let this->error = error;
        parent::__construct(message, httpStatus, uri, previous);
    }
}