#!perl -T

use Test::More tests => 1;

BEGIN {
	use_ok( 'Pixel::WCS' );
}

diag( "Testing Pixel::WCS $Pixel::WCS::VERSION, Perl $], $^X" );
