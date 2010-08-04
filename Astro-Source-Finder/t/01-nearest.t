#!/opt/local/bin/perl -T

use Test::More tests => 2;
use Astro::Source::Finder;

my $sf = Astro::Source::Finder::Finder->new("t","spi_acs",2);
ok(ref($sf) eq 'Astro::Source::Finder::Finder',"Astro::Source::Finder instantiation OK.");
can_ok($sf,'nearest');

my $srcid = $sf->nearest(10.,10.,10.);

if ($srcid =~ /FULL/) {
    diag("Member function nearest() works OK.");
} else {
    diag("Member function nearest() NOT working.");    
}
