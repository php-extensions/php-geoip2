namespace GeoIP2\Record;

abstract class AbstractPlaceRecord extends AbstractRecord
{
    protected locales;

    /**
     * @ignore
     *
     * @param mixed $record
     * @param mixed $locales
     */
    public function __construct(var record, array locales = ["en"])
    {
        let this->locales = locales;
        parent::__construct(record);
        this->filterLocales(locales);
    }

    protected function filterLocales(array locales)
    {
        var locale;
        if isset this->record["names"] {
            array validLocales = (array)array_keys(this->record["names"]);

            array _locales = [];
            for locale in locales {
                if in_array(locale, validLocales) {
                    let _locales[] =  locale;
                }
            }
            if !empty _locales {
                let locales = _locales;

                array names = [];

                for locale in locales {
                    if isset this->record["names"][locale] {
                        let names[locale] = this->record["names"][locale];
                    }
                }
                let this->record["names"] = names;
            } else {
                let locales = validLocales;
            }
            let this->locales = locales;
        }
    }

    /**
     * @ignore
     *
     * @param mixed $attr
     */
    public function __get(string attr)
    {
        if attr == "name" {
            return this->name();
        }
        if attr == "code" {
            if !this->__isset(attr) {
                let attr = "isoCode";
            }
        }
        if attr == "locales" {
            return this->locales;
        }
        return parent::__get(attr);
    }
    /**
     * @ignore
     *
     * @param mixed $attr
     */
    public function __isset(string attr)
    {
        if (attr === "name") {
            return this->firstSetNameLocale() === null ? false : true;
        }
        return parent::__isset(attr);
    }
    private function name()
    {
        var locale;
        let locale = this->firstSetNameLocale();
        return locale === null ? null : this->record["names"][locale];
    }
    private function firstSetNameLocale()
    {
        var locale;

        if in_array("en", this->locales) {
            return "en";
        }

        for locale in this->locales {
            if isset this->record["names"][locale] {
                return locale;
            }
        }
        return null;
    }
}