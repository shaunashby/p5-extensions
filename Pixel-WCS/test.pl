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
$wcs->search(83.6332, 22.0145, "FK5");

# Cyg X-1:
#  ra = 299.5903
#  dec = 35.2016
$wcs->search(299.5903, 35.2016, "FK5");
