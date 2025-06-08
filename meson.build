project('nx', 'c',
        version : '4.9.0',
        default_options : [
            'warning_level=1', # -Wall
            'werror=true', # -Werror
            'cpp_std=gnu++11', # -std=gnu++11
        ])

# The project source code is in the nx subdir
subdir('nx')

#---------------------------------------------------------------------------------
# Static library
#---------------------------------------------------------------------------------
# Compiler options
arch_opts = ['-march=armv8-a+crc+crypto', '-mtune=cortex-a57', '-mtp=soft', '-fPIC', '-ftls-model=local-exec']
c_opts = ['-g', '-ffunction-sections', '-fdata-sections'] + arch_opts
c_opts += ['-D__SWITCH__', '-DLIBNX_NO_DEPRECATION']
cpp_opts = ['-fno-rtti', '-fno-exceptions']

nx_lib = static_library('nx',
                        [c_src, s_src, data_gen_src],
                        include_directories : internal_inc,
                        c_args : c_opts,
                        cpp_args : cpp_opts)

nx_dep = declare_dependency(link_with : nx_lib, include_directories : inc)
