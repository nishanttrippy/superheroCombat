#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/trippy/Documents/GitHub/hw02-nishanttrippy
  make -f /Users/trippy/Documents/GitHub/hw02-nishanttrippy/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/trippy/Documents/GitHub/hw02-nishanttrippy
  make -f /Users/trippy/Documents/GitHub/hw02-nishanttrippy/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/trippy/Documents/GitHub/hw02-nishanttrippy
  make -f /Users/trippy/Documents/GitHub/hw02-nishanttrippy/CMakeScripts/ReRunCMake.make
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/trippy/Documents/GitHub/hw02-nishanttrippy
  make -f /Users/trippy/Documents/GitHub/hw02-nishanttrippy/CMakeScripts/ReRunCMake.make
fi

