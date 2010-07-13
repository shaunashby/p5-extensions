#!perl -T

use Test::More tests => 1;

BEGIN {
	use_ok( 'Astro::Source::Finder' );
}

diag( "Testing Astro::Source::Finder $Astro::Source::Finder::VERSION, Perl $], $^X" );
