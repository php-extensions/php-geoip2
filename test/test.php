<?php

use GeoIP2\Database\Reader;

//$ipAddress = '24.24.24.24';
//$ipAddress = '128.101.101.101';
$ipAddress = '8.8.8.8';
//$databaseFile = '/usr/share/GeoIP/GeoLite2-Country.mmdb';
$databaseFile = '/usr/share/GeoIP/GeoLite2-City.mmdb';

//$reader = new Reader($databaseFile, ['ru', 'en']);
$reader = new Reader($databaseFile);

echo "metadata\n";
print_r($reader->metadata()->__toArray());
//print_r((array)$reader->metadata());
//exit;

$record = $reader->city($ipAddress);

print($record->continent->code . "\n"); // 'US'
print($record->continent->name . "\n"); // 'US'
print($record->continent->names['ru'] . "\n"); // 'US'

//var_dump($record->country);
print($record->country->isoCode . "\n"); // 'US'
print($record->country->code . "\n"); // 'US'
print($record->country->name . "\n"); // 'United States'
print($record->country->names['en'] . "\n"); // 'United States'
print($record->country->names['zh-CN'] . "\n"); // '美国'
//var_dump($record->country);

print($record->mostSpecificSubdivision->name . "\n"); // 'Minnesota'
print($record->mostSpecificSubdivision->isoCode . "\n"); // 'MN'
print($record->mostSpecificSubdivision->code . "\n"); // 'MN'
print($record->subdivisions[0]->code . "\n"); // 'MN'

print($record->city->name . "\n"); // 'Minneapolis'

print($record->postal->code . "\n"); // '55455'

print($record->location->latitude . "\n"); // 44.9733
print($record->location->longitude . "\n"); // -93.2323

print($record->traits->ipAddress . "\n");

//print_r(json_encode($record->jsonSerialize()));
