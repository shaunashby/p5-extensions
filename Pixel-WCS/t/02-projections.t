#!perl -T

use lib "/tmp/lib/perl5/site_perl/5.8.9/darwin-2level";

use Test::More tests => 8;

use Pixel::WCS;

my $basedir = "./t";
my $instrument = "isgri";

my $wcs = Pixel::WCS::WCS->new($basedir,$instrument);

ok(ref($wcs) eq 'Pixel::WCS::WCS',"WCS module instantiated ok.");

# Check instrument and base dir returned correctly:
ok($wcs->instrument eq 'isgri',"Instrument correctly returned.");
ok($wcs->basedir eq './t',"Base directory correctly returned.");

# Get the projections:
my $projections = $wcs->projections;
ok(ref($projections) eq 'Pixel::WCS::Projections',"Projections pointer is of correct type.");

# Check coord system as read from the projection.fits:
ok($projections->coordsystem eq 'GALACTIC',"Coordinate system read from file is correct.");

# Check size of returned vector of regions:
my $regions = $projections->regions;
ok($regions->size == 6,"Projection regions vector has correct size.");

# Do lookup for a source, Crab:
my $source_ra = 83.6332;
my $source_dec = 22.0145;

my $region_for_source = undef;

for (my $i = 0; $i < $regions->size; $i++) {
    my $region = $regions->get($i);
    # Check to see if the source is in this region:
    if ($region->inside($source_ra, $source_dec)) {
	$region_for_source = $region;
    }
}

ok(defined($region_for_source),"Source found.");
ok($region_for_source->name eq 'glactic_center2',"Source found in correct region.");
