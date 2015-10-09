## SETTING THE INCLUDE DIRS
set(QTDCM_INCLUDE_DIRS
## Modules include dirs
  ${PROJECT_SOURCE_DIR}/src
)

## SETTING QTDCM LIBRARY DIRS
set(QTDCM_LIBRARY_DIRS
  ${LIBRARY_OUTPUT_PATH}
)

include_directories(${QTDCM_INCLUDE_DIRS})

## SETTING QTDCM LIBS
set(QTDCM_LIBS
  qtdcm
)