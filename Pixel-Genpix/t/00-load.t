#!perl -T

use Test::More tests => 1;

BEGIN {
	use_ok( 'Pixel::Genpix' );
}

diag( "Testing Pixel::Genpix $Pixel::Genpix::VERSION, Perl $], $^X" );
