#!perl -T

use Test::More tests => 4;

BEGIN {
	use_ok( 'Astro::Source::Finder' );
}

my $sf = Astro::Source::Finder::Finder->new("t","spi_acs",2);
ok(ref($sf) eq 'Astro::Source::Finder::Finder',"Astro::Source::Finder instantiation OK.");

can_ok($sf,'nearest');

my $srcid = $sf->nearest(10.,10.,10.);
ok($srcid eq "SOURCE_1","nearest() function works.");
