project('nx', 'c',
        version : '4.9.0',
        meson_version : '>= 1.4.0',
        default_options : [
            'warning_level=1', # -Wall
            'werror=true', # -Werror
            'cpp_std=gnu++11', # -std=gnu++11
        ])

#---------------------------------------------------------------------------------
# Options
#---------------------------------------------------------------------------------
# The `use_nx` global option is used to enable/disable the function overrides.
# If enabled, and the specialized options are in auto mode, the overrides are enabled.  
# If disabled, and the specialized options are in auto mode, the overrides are disabled.
# Individually, the specialized options can override the `use_nx` global option. 
use_nx = get_option('use_nx')

use_nx_alloc = get_option('use_nx_alloc').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_rand = get_option('use_nx_rand').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_svc = get_option('use_nx_svc').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_sys_sync = get_option('use_nx_sys_sync').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_sys_thread = get_option('use_nx_sys_thread').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_thread = get_option('use_nx_thread').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_time = get_option('use_nx_time').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())

#---------------------------------------------------------------------------------
# Dependencies
#---------------------------------------------------------------------------------
deps = []
deps_override_link_args = []

# nx-std
if (use_nx.enabled() 
    or use_nx_alloc.enabled() or use_nx_rand.enabled() or use_nx_svc.enabled() 
    or use_nx_sys_sync.enabled() or use_nx_sys_thread.enabled() or use_nx_thread.enabled() 
    or use_nx_time.enabled())
    
    nx_std_proj = subproject(
        'nx-std', 
        default_options : {
            'use_nx_alloc' : '@0@'.format(use_nx_alloc),
            'use_nx_rand' : '@0@'.format(use_nx_rand),
            'use_nx_svc' : '@0@'.format(use_nx_svc),
            'use_nx_sys_sync' : '@0@'.format(use_nx_sys_sync),
            'use_nx_sys_thread' : '@0@'.format(use_nx_sys_thread),
            'use_nx_thread' : '@0@'.format(use_nx_thread),
            'use_nx_time' : '@0@'.format(use_nx_time),
        },
    )


    debug('Using nx-std')
    deps += nx_std_proj.get_variable('nx_std_dep')
    deps_override_link_args += nx_std_proj.get_variable('nx_std_dep_override_link_args')
endif

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
                        dependencies : deps,
                        c_args : c_opts,
                        cpp_args : cpp_opts)

#---------------------------------------------------------------------------------
# Dependency declaration
#---------------------------------------------------------------------------------
nx_dep = declare_dependency(
    include_directories : nx_dep_inc,
    link_with : nx_lib, 
    link_args : deps_override_link_args,
    dependencies : deps,
)
