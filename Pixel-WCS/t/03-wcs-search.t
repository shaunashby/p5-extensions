#!perl -T

use lib "/tmp/lib/perl5/site_perl/5.8.9/darwin-2level";

use Test::More tests => 2;

use Pixel::WCS;

my $basedir = "./t";
my $instrument = "isgri";

my $wcs = Pixel::WCS::WCS->new($basedir,$instrument);

isa_ok($wcs,"Pixel::WCS::WCS");

# Search:
$wcs->search(288.778680, 10.926354, "FK5", 20, 20);

# Get the image params:
my $params = $wcs->params();
isa_ok($params,"Pixel::WCS::ImageParams");
