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
use warnings;
use strict;

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

my $axis_a =288.778680;
my $axis_b = 10.926354;

$wcs->search($axis_a, $axis_b, "FK5", 20, 20);

my $params = $wcs->params();

my $crf   = $params->coordrefframe();
my $ceq   = $params->coordequinox();
my $copr  = $params->coordprojection();
my $crpa  = $params->coordrefpixelA();
my $crpb  = $params->coordrefpixelB();
my $crva  = $params->coordrefvalueA();
my $crvb  = $params->coordrefvalueB();

# Rotation matrices:
my $cd1_1 = $params->cd()->get(0);
my $cd1_2 = $params->cd()->get(1);
my $cd2_1 = $params->cd()->get(2);
my $cd2_2 = $params->cd()->get(3);

my $size_x  = $params->size_x();
my $size_y  = $params->size_y();
my $scale_a = $params->scaleA();
my $scale_b = $params->scaleB();


my $out= "Axis_A=".$axis_a."\n";
$out.="Axis_B=10.926354".$axis_b."\n";
$out.="Size_A=".$size_x."\n";
$out.="Size_B=".$size_y."\n";
$out.="Scale_A=".$scale_a."\n";
$out.="Scale_B=".$scale_b."\n";
$out.="CoordRefFrame=".$crf."\n";
$out.="CoordEquinox=".$ceq."\n";
$out.="CoordProjection=".$copr."\n";
$out.="CoordRefPixel_A=".$crpa."\n";
$out.="CoordRefPixel_B=".$crpb."\n";
$out.="CoordRefValue_A=".$crva."\n";
$out.="CoordRefValue_B=".$crvb."\n";
$out.="CD1_1=".$cd1_1."\n";
$out.="CD1_2=".$cd1_2."\n";
$out.="CD2_1=".$cd2_1."\n";
$out.="CD2_2=".$cd2_2."\n";
    
print $out,"\n";
