use strict;
use warnings;
use ExtUtils::MakeMaker;

WriteMakefile(
    NAME                => 'Pixel::Genpix',
    AUTHOR              => 'Shaun ASHBY <shaun.ashby@unige.ch>',
    VERSION_FROM        => 'lib/Pixel/Generate.pm',
    ($ExtUtils::MakeMaker::VERSION >= 6.3002
      ? ('LICENSE'=> 'perl')
      : ()),
    PL_FILES            => {},
    CCFLAGS           => '-fno-common -DPERL_DARWIN -no-cpp-precomp -fno-strict-aliasing -pipe',
    LIBS              => ['-L/osa_sw-9.0-intel/lib -ldal3gen -ldal -lcfitsio -lwcs'],
    CC                => 'g++',
    LD                => 'g++',
    DEFINE            => '-I../',
    INC               => '-I. -I/osa_sw-9.0-intel/include',
    OBJECT            => '$(O_FILES) Genpix_wrap.o',
    PREREQ_PM => {
        'Test::More' => 0,
    },
    dist                => { COMPRESS => 'gzip -9f', SUFFIX => 'gz', },
    clean               => { FILES => 'Pixel-Genpix-*' },
);

sub MY::postamble {
    return <<'MAKE_FRAG';
SWIG=$(shell which swig)
MODULE_NAMESPACE=Pixel

blib/$(MODULE_NAMESPACE)/%.pm: %.i %.h
	@echo ">> Updating $@:"
	-cp $@ $(DESTINSTALLSITELIB)

%_wrap.cxx: %.i %.h
	@echo "Creating glue ($@) from $< using SWIG:"
	$(SWIG) -outdir lib/$(MODULE_NAMESPACE) -Wall -perl5 -shadow -c++ $<

MAKE_FRAG
    }
