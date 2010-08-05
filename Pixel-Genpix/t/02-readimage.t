#!perl -T

use Test::More tests => 1;

use Pixel::Genpix;

my $gpx = Pixel::Genpix::Genpix->new();
my $img = "./t/data/isgri_sky_ima.fits.gz";

ok($gpx->readimage($img),"Reading image file.");
