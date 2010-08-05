#!perl -T

use Test::More tests => 3;

use Pixel::Genpix;

my $gpx = Pixel::Genpix::Genpix->new();

isa_ok($gpx,'Pixel::Genpix::Genpix');
can_ok($gpx,'readimage');
can_ok($gpx,'save');
