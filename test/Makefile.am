check_PROGRAMS = test-multinv

TESTS = test-multinv

test_multinv_SOURCES = test.cc

test_multinv_CPPFLAGS = -I$(top_srcdir)/src

test_multinv_CXXFLAGS = $(WARN_CXXFLAGS)

test_multinv_LDADD = $(top_builddir)/src/libmultinv.la

test_multinv_LDFLAGS = $(WARN_LDFLAGS)

-include $(top_srcdir)/git.mk
