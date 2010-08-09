#!perl -T

use Test::More tests => 3;

use Pixel::Genpix;

my $img = "./t/data/isgri_sky_ima.fits.gz";
my $refimg = "./t/data/glactic_center2_isgri.fits.gz";
my $gpx = Pixel::Genpix::Genpix->new($img, $refimg, 42.5, 137.5, -47.5, 47.5);

isa_ok($gpx,'Pixel::Genpix::Genpix');
can_ok($gpx,'read_reference');
can_ok($gpx,'save');
