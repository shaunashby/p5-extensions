#!/usr/bin/perl 
#____________________________________________________________________ 
# File: test.pl
#____________________________________________________________________ 
#  
# Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
# Update: 2010-07-26 10:48:28+0200
# Revision: $Id$ 
#
# Copyright: 2010 (C) Shaun ASHBY
#
#--------------------------------------------------------------------
use lib "/tmp/lib/perl5/site_perl/5.8.9/darwin-2level";

use Pixel::WCS;

my $basedir = "./t";
my $instrument = "isgri";

my $wcs = Pixel::WCS::WCS->new($basedir, $instrument);

# Crab:
#  ra 83.6332
#  dec 22.0145
# $wcs->search(83.6332, 22.0145, "FK5");

# Cyg X-1:
#  ra = 299.5903
#  dec = 35.2016
#$wcs->search(299.5903, 35.2016, "FK5");


$wcs->search(288.778680, 10.926354, "FK5", 20, 20);

my $params = $wcs->params();

print $params->coordrefframe(),"\n";
print $params->coordrefpixelA(),"\n";

#my @rot = $params->cd();
#print $$rot[0],"\n";

__DATA__

#     "Axis_A=288.778680",
#     "Axis_B=10.926354",
#     "Size_A=20",
#     "Size_B=20",
#     "Scale_A=0.070407",
#     "Scale_B=0.070407",
#     "CoordRefFrame=",
#     "CoordEquinox=2000",
#     "CoordProjection=STG",
#     "CoordRefPixel_A=-561.5",
#     "CoordRefPixel_B=13.5",
#     "CoordRefValue_A=90.000000",
#     "CoordRefValue_B=0.000000",
#     "CD1_1=-0.0822862539155913",
#     "CD1_2=0.0000000000000000",
#     "CD2_1=0.0000000000000000",
#     "CD2_2=0.0822862539155913"
    
