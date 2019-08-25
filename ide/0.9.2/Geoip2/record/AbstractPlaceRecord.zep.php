<?php

namespace GeoIP2\Record;


abstract class AbstractPlaceRecord extends \GeoIP2\Record\AbstractRecord
{

    protected $locales;


    /**
     * @ignore
     *
     * @param mixed $record
     * @param mixed $locales
     */
    public function __construct($record, array $locales = array('en')) {}

    /**
     * @param array $locales
     */
    protected function filterLocales(array $locales) {}

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


    private function name() {}


    private function firstSetNameLocale() {}

}
