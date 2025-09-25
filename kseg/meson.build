project('segment-kmeans-port', 'c',
  version : '0.1',
  license : 'GPL-3.0-or-later')

# These arguments are only used to build the shared library
# not the executables that use the library.
lib_args = ['-DBUILDING_GEGLFILTER']

gegl = dependency('gegl-0.4', required : false)
if not gegl.found()
    gegl = dependency('gegl-0.5')
endif

cc        = meson.get_compiler('c')

math    = cc.find_library('m',  required: true)

shlib = shared_library('segment-kmeans-port', 'segment-kmeans-port.c', 'config.h', 
  c_args : lib_args,
  dependencies : [ gegl, math ],
  name_prefix : '',
)

# Make this library usable as a Meson subproject.
stroke_dep = declare_dependency(
  include_directories: include_directories('.'),
  link_with : shlib)
