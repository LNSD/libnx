project('nx', 'c',
        version : '4.7.0',
        default_options : [
            'warning_level=1', # -Wall
            'werror=true', # -Werror
            'cpp_std=gnu++11', # -std=gnu++11
        ])

#---------------------------------------------------------------------------------
# Dependencies
#---------------------------------------------------------------------------------
# nx-svc
nx_svc_proj = subproject('nx-svc')
nx_svc_dep = nx_svc_proj.get_variable('nx_svc_dep')

#---------------------------------------------------------------------------------
# Static library
#---------------------------------------------------------------------------------
# The project source code is in the nx subdir
subdir('nx')

# Compiler options
arch_opts = ['-march=armv8-a+crc+crypto', '-mtune=cortex-a57', '-mtp=soft', '-fPIC', '-ftls-model=local-exec']
c_opts = ['-g', '-ffunction-sections', '-fdata-sections'] + arch_opts
c_opts += ['-D__SWITCH__', '-DLIBNX_NO_DEPRECATION']
cpp_opts = ['-fno-rtti', '-fno-exceptions']

nx_lib = static_library('nx',
                        [c_src, s_src, data_gen_src],
                        include_directories : internal_inc,
                        dependencies : [nx_svc_dep],
                        c_args : c_opts,
                        cpp_args : cpp_opts)

nx_dep = declare_dependency(link_with : nx_lib, include_directories : inc)
