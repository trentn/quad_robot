set(SUBDIRS
        libraries
        test_apps)

foreach(subdir ${SUBDIRS})
    add_subdirectory(${subdir})
endforeach()
