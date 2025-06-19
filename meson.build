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
use_nx_sync = get_option('use_nx_sync').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_thread = get_option('use_nx_thread').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_thread_tls = get_option('use_nx_thread_tls').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())
use_nx_time = get_option('use_nx_time').enable_auto_if(use_nx.enabled()).disable_auto_if(use_nx.disabled())

#---------------------------------------------------------------------------------
# Dependencies
#---------------------------------------------------------------------------------
deps = []

# nx-alloc
if use_nx_alloc.enabled()
    message('Using nx-alloc')
    nx_alloc_proj = subproject('nx-alloc')

    deps += nx_alloc_proj.get_variable('nx_alloc_dep')
endif

# nx-rand
if use_nx_rand.enabled()
    message('Using nx-rand')
    nx_rand_proj = subproject('nx-rand')

    deps += nx_rand_proj.get_variable('nx_rand_dep')
endif


# nx-svc
if use_nx_svc.enabled()
    message('Using nx-svc')
    nx_svc_proj = subproject('nx-svc')

    deps += nx_svc_proj.get_variable('nx_svc_dep')
endif

# nx-sync
if use_nx_sync.enabled()
    message('Using nx-sync')
    nx_sync_proj = subproject('nx-sync')

    deps += nx_sync_proj.get_variable('nx_sync_dep')
endif

# nx-thread
if use_nx_thread.enabled()
    message('Using nx-thread')
    nx_thread_proj = subproject('nx-thread')

    deps += nx_thread_proj.get_variable('nx_thread_dep')
endif

# nx-thread-tls
if use_nx_thread_tls.enabled()
    message('Using nx-thread-tls')
    nx_thread_tls_proj = subproject('nx-thread-tls')

    deps += nx_thread_tls_proj.get_variable('nx_thread_tls_dep')
endif

# nx-time
if use_nx_time.enabled()
    message('Using nx-time')
    nx_time_proj = subproject('nx-time')

    deps += nx_time_proj.get_variable('nx_time_dep')
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
nx_dep_deps = []
nx_dep_link_args = []

# Override alloc functions and propagate nx-alloc dependency
if use_nx_alloc.enabled()
    nx_alloc_proj = subproject('nx-alloc')

    nx_dep_deps += nx_alloc_proj.get_variable('nx_alloc_dep')
    nx_dep_link_args += ['-T', nx_alloc_proj.get_variable('nx_alloc_ld_override')]
endif

# Override random functions and propagate nx-rand dependency
if use_nx_rand.enabled()
    nx_rand_proj = subproject('nx-rand')

    nx_dep_deps += nx_rand_proj.get_variable('nx_rand_dep')
    nx_dep_link_args += ['-T', nx_rand_proj.get_variable('nx_rand_ld_override')]
endif


# Override SVC functions and propagate nx-svc dependency
if use_nx_svc.enabled()
    nx_svc_proj = subproject('nx-svc')

    nx_dep_deps += nx_svc_proj.get_variable('nx_svc_dep')
    nx_dep_link_args += ['-T', nx_svc_proj.get_variable('nx_svc_ld_override')]
endif

# Override sync functions and propagate nx-sync dependency
if use_nx_sync.enabled()
    nx_sync_proj = subproject('nx-sync')

    nx_dep_deps += nx_sync_proj.get_variable('nx_sync_dep')
    nx_dep_link_args += ['-T', nx_sync_proj.get_variable('nx_sync_ld_override')]
endif

# Override thread functions and propagate nx-thread dependency
if use_nx_thread.enabled()
    nx_thread_proj = subproject('nx-thread')

    nx_dep_deps += nx_thread_proj.get_variable('nx_thread_dep')
    nx_dep_link_args += ['-T', nx_thread_proj.get_variable('nx_thread_ld_override')]
endif

# Override thread functions and propagate nx-thread dependency
if use_nx_thread_tls.enabled()
    nx_thread_tls_proj = subproject('nx-thread-tls')

    nx_dep_deps += nx_thread_tls_proj.get_variable('nx_thread_tls_dep')
    nx_dep_link_args += ['-T', nx_thread_tls_proj.get_variable('nx_thread_tls_ld_override')]
endif

# Override time functions and propagate nx-time dependency
if use_nx_time.enabled()
    nx_time_proj = subproject('nx-time')

    nx_dep_deps += nx_time_proj.get_variable('nx_time_dep')
    nx_dep_link_args += ['-T', nx_time_proj.get_variable('nx_time_ld_override')]
endif


nx_dep = declare_dependency(
    link_with : nx_lib, 
    include_directories : nx_dep_inc,
    dependencies : nx_dep_deps,
    link_args : nx_dep_link_args,
)
