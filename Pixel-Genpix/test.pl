#!/usr/bin/perl 
#____________________________________________________________________ 
# File: test.pl
#____________________________________________________________________ 
#  
# Author: Shaun ASHBY <Shaun.Ashby@gmail.com>
# Update: 2010-08-09 18:03:25+0200
# Revision: $Id$ 
#
# Copyright: 2010 (C) Shaun ASHBY
#
#--------------------------------------------------------------------
use warnings;
use strict;

use Pixel::Genpix;
# [INFO]   lowL  = 4.250000000000000E+01
# [INFO]   highL = 1.375000000000000E+02
# [INFO]   lowB  = -4.750000000000000E+01
# [INFO]   highB = 4.750000000000000E+01
# [INFO]   outputArea     = pixels/isgri/glactic_center2/0
# [INFO]   referenceImage = pixels/isgri/glactic_center2/glactic_center2_isgri.fits[1]
my $img = "./t/data/isgri_sky_ima.fits.gz";
my $refimg = "./t/data/glactic_center2_isgri.fits.gz[1]";
my $gpx = Pixel::Genpix::Genpix->new($img, $refimg, 42.5, 137.5, -47.5, 47.5);
