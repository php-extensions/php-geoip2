# PHP GeoIP2 extension

## Description

This extension provides an API for the MaxMind
[GeoIP2 databases](http://dev.maxmind.com/geoip/geoip2/downloadable) and free
[GeoLite2 databases](http://dev.maxmind.com/geoip/geoip2/geolite2/).

This extension is a port of the official [MaxMind GeoIP2 PHP package](https://github.com/maxmind/GeoIP2-php)
and [MaxMind DB Reader PHP package](https://github.com/maxmind/MaxMind-DB-Reader-php).
It is written in Zephir and converted to C.

### Requirements

Since version 0.9.2 this extension requires PHP 7 or greater.

### Building extension

#### Prerequisites

Since version 0.9.2, gcc 7+ is required. To enable it on CentOS:

```
yum install -y yum-utils  centos-release-scl
yum -y --enablerepo=centos-sclo-rh-testing install devtoolset-7-gcc
echo "source /opt/rh/devtoolset-7/enable" | sudo tee -a /etc/profile
source /opt/rh/devtoolset-7/enable
```

Building with Zephir (recommended)

```
zephir compile
zephir install
```

Building without Zephir

```
cd ext
phpize
./configure
make
make install
```

This extension can also read custom databases created using
[MaxMind DB Writer](https://github.com/maxmind/MaxMind-DB-Writer-perl]).

```
use GeoIP2\Database\Reader;

$ipAddress = '8.8.8.8';
$databaseFile = 'mydb.mmdb';

$reader = new Reader($databaseFile);

print_r($record = $reader->custom($ipAddress));

print_r($record->raw['color']);
print_r($record->get('dogs'));
```

## IP Geolocation Usage

IP geolocation is inherently imprecise. Locations are often near the center of
the population. Any location provided by a GeoIP2 database or web service
should not be used to identify a particular address or household.

## Database Reader

### Usage

To use this API, you must create a new `\GeoIP2\Database\Reader` object with
the path to the database file as the first argument to the constructor. You
may then call the method corresponding to the database you are using.

If the lookup succeeds, the method call will return a model class for the
record in the database. This model in turn contains multiple container
classes for the different parts of the data such as the city in which the
IP address is located.

If the record is not found, a `\GeoIP2\Exception\AddressNotFoundException`
is thrown. If the database is invalid or corrupt, a
`\GeoIP2\Exception\InvalidDatabaseException` will be thrown.

See the API documentation for more details.

### City Example

```php
<?php

use GeoIP2\Database\Reader;

// This creates the Reader object, which should be reused across
// lookups.
$reader = new Reader('/usr/share/GeoIP/GeoIP2-City.mmdb');

// Replace "city" with the appropriate method for your database, e.g.,
// "country".
$record = $reader->city('128.101.101.101');

print($record->country->isoCode . "\n"); // 'US'
print($record->country->name . "\n"); // 'United States'
print($record->country->names['zh-CN'] . "\n"); // '美国'

print($record->mostSpecificSubdivision->name . "\n"); // 'Minnesota'
print($record->mostSpecificSubdivision->isoCode . "\n"); // 'MN'

print($record->city->name . "\n"); // 'Minneapolis'

print($record->postal->code . "\n"); // '55455'

print($record->location->latitude . "\n"); // 44.9733
print($record->location->longitude . "\n"); // -93.2323

```

### Anonymous IP Example

```php
<?php

use GeoIP2\Database\Reader;

// This creates the Reader object, which should be reused across
// lookups.
$reader = new Reader('/usr/share/GeoIP/GeoIP2-Anonymous-IP.mmdb');

$record = $reader->anonymousIp('128.101.101.101');

if ($record->isAnonymous) { print "anon\n"; }
print($record->ipAddress . "\n"); // '128.101.101.101'

```

### Connection-Type Example

```php
<?php

use GeoIP2\Database\Reader;

// This creates the Reader object, which should be reused across
// lookups.
$reader = new Reader('/usr/share/GeoIP/GeoIP2-Connection-Type.mmdb');

$record = $reader->connectionType('128.101.101.101');

print($record->connectionType . "\n"); // 'Corporate'
print($record->ipAddress . "\n"); // '128.101.101.101'

```

### Domain Example

```php
<?php

use GeoIP2\Database\Reader;

// This creates the Reader object, which should be reused across
// lookups.
$reader = new Reader('/usr/share/GeoIP/GeoIP2-Domain.mmdb');

$record = $reader->domain('128.101.101.101');

print($record->domain . "\n"); // 'umn.edu'
print($record->ipAddress . "\n"); // '128.101.101.101'

```

### Enterprise Example

```php
<?php

use GeoIP2\Database\Reader;

// This creates the Reader object, which should be reused across
// lookups.
$reader = new Reader('/usr/share/GeoIP/GeoIP2-Enterprise.mmdb');

// Use the ->enterprise method to do a lookup in the Enterprise database
$record = $reader->enterprise('128.101.101.101');

print($record->country->confidence . "\n"); // 99
print($record->country->isoCode . "\n"); // 'US'
print($record->country->name . "\n"); // 'United States'
print($record->country->names['zh-CN'] . "\n"); // '美国'

print($record->mostSpecificSubdivision->confidence . "\n"); // 77
print($record->mostSpecificSubdivision->name . "\n"); // 'Minnesota'
print($record->mostSpecificSubdivision->isoCode . "\n"); // 'MN'

print($record->city->confidence . "\n"); // 60
print($record->city->name . "\n"); // 'Minneapolis'

print($record->postal->code . "\n"); // '55455'

print($record->location->accuracyRadius . "\n"); // 50
print($record->location->latitude . "\n"); // 44.9733
print($record->location->longitude . "\n"); // -93.2323

```

### ISP Example

```php
<?php

use GeoIP2\Database\Reader;

// This creates the Reader object, which should be reused across
// lookups.
$reader = new Reader('/usr/share/GeoIP/GeoIP2-ISP.mmdb');

$record = $reader->isp('128.101.101.101');

print($record->autonomousSystemNumber . "\n"); // 217
print($record->autonomousSystemOrganization . "\n"); // 'University of Minnesota'
print($record->isp . "\n"); // 'University of Minnesota'
print($record->organization . "\n"); // 'University of Minnesota'

print($record->ipAddress . "\n"); // '128.101.101.101'

```

## Values to use for Database or Array Keys

**We strongly discourage you from using a value from any `names` property as
a key in a database or array.**

These names may change between releases. Instead we recommend using one of the
following:

* `GeoIP2\Record\City` - `$city->geonameId`
* `GeoIP2\Record\Continent` - `$continent->code` or `$continent->geonameId`
* `GeoIP2\Record\Country` and `GeoIP2\Record\RepresentedCountry` -
  `$country->isoCode` or `$country->geonameId`
* `GeoIP2\Record\Subdivision` - `$subdivision->isoCode` or `$subdivision->geonameId`

### What data is returned?

While many of the end points return the same basic records, the attributes
which can be populated vary between end points. In addition, while an end
point may offer a particular piece of data, MaxMind does not always have every
piece of data for any given IP address.

Because of these factors, it is possible for any end point to return a record
where some or all of the attributes are unpopulated.

See the
[GeoIP2 Precision web service docs](http://dev.maxmind.com/geoip/geoip2/web-services)
for details on what data each end point may return.

The only piece of data which is always returned is the `ipAddress`
attribute in the `GeoIP2\Record\Traits` record.

## Integration with GeoNames

[GeoNames](http://www.geonames.org/) offers web services and downloadable
databases with data on geographical features around the world, including
populated places. They offer both free and paid premium data. Each
feature is unique identified by a `geonameId`, which is an integer.

Many of the records returned by the GeoIP2 web services and databases
include a `geonameId` property. This is the ID of a geographical feature
(city, region, country, etc.) in the GeoNames database.

Some of the data that MaxMind provides is also sourced from GeoNames. We
source things like place names, ISO codes, and other similar data from
the GeoNames premium data set.

## Reporting data problems

If the problem you find is that an IP address is incorrectly mapped,
please
[submit your correction to MaxMind](http://www.maxmind.com/en/correction).

If you find some other sort of mistake, like an incorrect spelling,
please check the [GeoNames site](http://www.geonames.org/) first. Once
you've searched for a place and found it on the GeoNames map view, there
are a number of links you can use to correct data ("move", "edit",
"alternate names", etc.). Once the correction is part of the GeoNames
data set, it will be automatically incorporated into future MaxMind
releases.

If you are a paying MaxMind customer and you're not sure where to submit
a correction, please
[contact MaxMind support](http://www.maxmind.com/en/support) for help.

## Other Support

Please report all issues with this code using the
[GitHub issue tracker](https://github.com/php-extensions/php-geoip2/issues).

If you are having an issue with a MaxMind service that is not specific
to the client API, please see
[MaxMind support page](http://www.maxmind.com/en/support).
