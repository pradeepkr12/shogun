MACRO(MergeCFLAGS)
	SET(MERGED_C_FLAGS ${CMAKE_C_FLAGS})
	SET(MERGED_CXX_FLAGS ${CMAKE_CXX_FLAGS})

	IF (CMAKE_BUILD_TYPE MATCHES Release)
		SET(MERGED_C_FLAGS "${MERGED_C_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
		SET(MERGED_CXX_FLAGS "${MERGED_CXX_FLAGS} ${CMAKE_CXX_FLAGS_RELEASE}")
	ELSEIF (CMAKE_BUILD_TYPE MATCHES Distribution)
		SET(MERGED_C_FLAGS "${MERGED_C_FLAGS} ${CMAKE_C_FLAGS_DISTRIBUTION}")
		SET(MERGED_CXX_FLAGS "${MERGED_CXX_FLAGS} ${CMAKE_CXX_FLAGS_DISTRIBUTION}")
	ENDIF()
ENDMACRO()

MACRO(GetCompilers)
	IF(CCACHE_FOUND AND ENABLE_CCACHE)
		SET(C_COMPILER ${CMAKE_C_COMPILER_ARG1})
		SET(CXX_COMPILER ${CMAKE_CXX_COMPILER_ARG1})
	ELSE()
		SET(C_COMPILER ${CMAKE_C_COMPILER})
		SET(CXX_COMPILER ${CMAKE_CXX_COMPILER})
	ENDIF()
ENDMACRO()