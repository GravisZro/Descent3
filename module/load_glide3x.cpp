#include "load_glide3x.h"

// System
#include <stdio.h>

#ifndef GLIDELIB
# ifdef __unix__
  constexpr const char* const GLIDE3XLIB = "libglide3x.so";
# elif defined(_WIN32) || defined(__CYGWIN__)
  constexpr const char* const GLIDELIB = "glide3x.dll";
# endif
#endif

namespace glide
{
  /* rendering functions */
  void  (STDCALL *grDrawPoint)(const void* pt) = nullptr;
  void  (STDCALL *grDrawLine)(const void* v1, const void* v2) = nullptr;
  void  (STDCALL *grDrawTriangle)(const void* a, const void* b, const void* c) = nullptr;
  void  (STDCALL *grVertexLayout)(uint32_t param, int32_t offset, uint32_t mode) = nullptr;
  void  (STDCALL *grDrawVertexArray)(uint32_t mode, uint32_t Count, void* pointers) = nullptr;
  void  (STDCALL *grDrawVertexArrayContiguous)(uint32_t mode, uint32_t Count, void* pointers, uint32_t stride) = nullptr;

  /* Antialiasing Functions */
  void  (STDCALL *grAADrawTriangle)(const void* a, const void* b, const void* c, bool32_t ab_antialias, bool32_t bc_antialias, bool32_t ca_antialias) = nullptr;

  /* buffer management */
  void  (STDCALL *grBufferClear)(GrColor_t color, GrAlpha_t alpha, uint32_t depth) = nullptr;
  void  (STDCALL *grBufferSwap)(int swap_interval) = nullptr;
  void  (STDCALL *grRenderBuffer)(GrBuffer_t buffer) = nullptr;

  /* error management */
  void  (STDCALL *grErrorSetCallback)(void (*callback)(const char* string, bool32_t fatal)) = nullptr;

  /* SST routines */
  void  (STDCALL *grFinish)(void) = nullptr;
  void  (STDCALL *grFlush)(void) = nullptr;
  GrContext_t  (STDCALL *grSstWinOpen)(uint32_t hWnd, GrScreenResolution_t screen_resolution, GrScreenRefresh_t refresh_rate, GrColorFormat_t color_format, GrOriginLocation_t origin_location, int nColBuffers, int nAuxBuffers) = nullptr;
  bool32_t  (STDCALL *grSstWinClose)(GrContext_t context) = nullptr;
  bool32_t  (STDCALL *grSelectContext)(GrContext_t context) = nullptr;
  void  (STDCALL *grSstOrigin)(GrOriginLocation_t origin) = nullptr;
  void  (STDCALL *grSstSelect)(int which_sst) = nullptr;

  /* Glide configuration and special effect maintenance functions */
  void  (STDCALL *grAlphaBlendFunction)(GrAlphaBlendFnc_t rgb_sf, GrAlphaBlendFnc_t rgb_df, GrAlphaBlendFnc_t alpha_sf, GrAlphaBlendFnc_t alpha_df) = nullptr;
  void  (STDCALL *grAlphaCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, bool32_t invert) = nullptr;
  void  (STDCALL *grAlphaControlsITRGBLighting)(bool32_t enable) = nullptr;
  void  (STDCALL *grAlphaTestFunction)(GrCmpFnc_t function) = nullptr;
  void  (STDCALL *grAlphaTestReferenceValue)(GrAlpha_t value) = nullptr;
  void  (STDCALL *grChromakeyMode)(GrChromakeyMode_t mode) = nullptr;
  void  (STDCALL *grChromakeyValue)(GrColor_t value) = nullptr;
  void  (STDCALL *grClipWindow)(uint32_t minx, uint32_t miny, uint32_t maxx, uint32_t maxy) = nullptr;
  void  (STDCALL *grColorCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, bool32_t invert) = nullptr;
  void  (STDCALL *grColorMask)(bool32_t rgb, bool32_t a) = nullptr;
  void  (STDCALL *grCullMode)(GrCullMode_t mode) = nullptr;
  void  (STDCALL *grConstantColorValue)(GrColor_t value) = nullptr;
  void  (STDCALL *grDepthBiasLevel)(uint32_t level) = nullptr;
  void  (STDCALL *grDepthBufferFunction)(GrCmpFnc_t function) = nullptr;
  void  (STDCALL *grDepthBufferMode)(GrDepthBufferMode_t mode) = nullptr;
  void  (STDCALL *grDepthMask)(bool32_t mask) = nullptr;
  void  (STDCALL *grDisableAllEffects)(void) = nullptr;
  void  (STDCALL *grDitherMode)(GrDitherMode_t mode) = nullptr;
  void  (STDCALL *grFogColorValue)(GrColor_t fogcolor) = nullptr;
  void  (STDCALL *grFogMode)(GrFogMode_t mode) = nullptr;
  void  (STDCALL *grFogTable)(const GrFog_t ft[]) = nullptr;
  void  (STDCALL *grLoadGammaTable)(uint32_t nentries, uint32_t* red, uint32_t* green, uint32_t* blue) = nullptr;
  void  (STDCALL *grSplash)(float x, float y, float width, float height, uint32_t frame) = nullptr;
  bool32_t  (STDCALL *grGet)(uint32_t pname, uint32_t plength, int32_t* params) = nullptr;
  const char*  (STDCALL *grGetString)(uint32_t pname) = nullptr;
  int32_t  (STDCALL *grQueryResolutions)(const GrResolution* resTemplate, GrResolution* output) = nullptr;
  bool32_t  (STDCALL *grReset)(uint32_t what) = nullptr;
  GrProc  (STDCALL *grGetProcAddress)(char* procName) = nullptr;
  void  (STDCALL *grEnable)(GrEnableMode_t mode) = nullptr;
  void  (STDCALL *grDisable)(GrEnableMode_t mode) = nullptr;
  void  (STDCALL *grCoordinateSpace)(GrCoordinateSpaceMode_t mode) = nullptr;
  void  (STDCALL *grDepthRange)(float n, float f) = nullptr;
  void  (STDCALL *grViewport)(int32_t x, int32_t y, int32_t width, int32_t height) = nullptr;

  /* texture mapping control functions */
  uint32_t  (STDCALL *grTexCalcMemRequired)(GrLOD_t lodmin, GrLOD_t lodmax, GrAspectRatio_t aspect, GrTextureFormat_t fmt) = nullptr;
  uint32_t  (STDCALL *grTexTextureMemRequired)(uint32_t evenOdd, GrTexInfo* info) = nullptr;
  uint32_t  (STDCALL *grTexMinAddress)(GrChipID_t tmu) = nullptr;
  uint32_t  (STDCALL *grTexMaxAddress)(GrChipID_t tmu) = nullptr;
  void  (STDCALL *grTexNCCTable)(GrNCCTable_t table) = nullptr;
  void  (STDCALL *grTexSource)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo* info) = nullptr;
  void  (STDCALL *grTexClampMode)(GrChipID_t tmu, GrTextureClampMode_t s_clampmode, GrTextureClampMode_t t_clampmode) = nullptr;
  void  (STDCALL *grTexCombine)(GrChipID_t tmu, GrCombineFunction_t rgb_function, GrCombineFactor_t rgb_factor, GrCombineFunction_t alpha_function, GrCombineFactor_t alpha_factor, bool32_t rgb_invert, bool32_t alpha_invert) = nullptr;
  void  (STDCALL *grTexDetailControl)(GrChipID_t tmu, int lod_bias, uint8_t detail_scale, float detail_max) = nullptr;
  void  (STDCALL *grTexFilterMode)(GrChipID_t tmu, GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode) = nullptr;
  void  (STDCALL *grTexLodBiasValue)(GrChipID_t tmu, float bias) = nullptr;
  void  (STDCALL *grTexDownloadMipMap)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo* info) = nullptr;
  void  (STDCALL *grTexDownloadMipMapLevel)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void* data) = nullptr;
  bool32_t  (STDCALL *grTexDownloadMipMapLevelPartial)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void* data, int start, int end) = nullptr;
  void  (STDCALL *grTexDownloadTable)(GrTexTable_t type, void* data) = nullptr;
  void  (STDCALL *grTexDownloadTablePartial)(GrTexTable_t type, void* data, int start, int end) = nullptr;
  void  (STDCALL *grTexMipMapMode)(GrChipID_t tmu, GrMipMapMode_t mode, bool32_t lodBlend) = nullptr;
  void  (STDCALL *grTexMultibase)(GrChipID_t tmu, bool32_t enable) = nullptr;
  void  (STDCALL *grTexMultibaseAddress)(GrChipID_t tmu, GrTexBaseRange_t range, uint32_t startAddress, uint32_t evenOdd, GrTexInfo* info) = nullptr;

  /* linear frame buffer functions */
  bool32_t  (STDCALL *grLfbLock)(GrLock_t type, GrBuffer_t buffer, GrLfbWriteMode_t writeMode, GrOriginLocation_t origin, bool32_t pixelPipeline, GrLfbInfo_t* info) = nullptr;
  bool32_t  (STDCALL *grLfbUnlock)(GrLock_t type, GrBuffer_t buffer) = nullptr;
  void  (STDCALL *grLfbConstantAlpha)(GrAlpha_t alpha) = nullptr;
  void  (STDCALL *grLfbConstantDepth)(uint32_t depth) = nullptr;
  void  (STDCALL *grLfbWriteColorSwizzle)(bool32_t swizzleBytes, bool32_t swapWords) = nullptr;
  void  (STDCALL *grLfbWriteColorFormat)(GrColorFormat_t colorFormat) = nullptr;
  bool32_t  (STDCALL *grLfbWriteRegion)(GrBuffer_t dst_buffer, uint32_t dst_x, uint32_t dst_y, GrLfbSrcFmt_t src_format, uint32_t src_width, uint32_t src_height, bool32_t pixelPipeline, int32_t src_stride, void* src_data) = nullptr;
  bool32_t  (STDCALL *grLfbReadRegion)(GrBuffer_t src_buffer, uint32_t src_x, uint32_t src_y, uint32_t src_width, uint32_t src_height, uint32_t dst_stride, void* dst_data) = nullptr;

  /* glide management functions */
  void  (STDCALL *grGlideInit)(void) = nullptr;
  void  (STDCALL *grGlideShutdown)(void) = nullptr;
  void  (STDCALL *grGlideGetState)(void* state) = nullptr;
  void  (STDCALL *grGlideSetState)(const void* state) = nullptr;
  void  (STDCALL *grGlideGetVertexLayout)(void* layout) = nullptr;
  void  (STDCALL *grGlideSetVertexLayout)(const void* layout) = nullptr;

  /* Gamma functions */
  void  (STDCALL *guGammaCorrectionRGB)(float red, float green, float blue) = nullptr;

  /* fog stuff */
  float  (STDCALL *guFogTableIndexToW)(int i) = nullptr;
  void  (STDCALL *guFogGenerateExp)(GrFog_t* fogtable, float density) = nullptr;
  void  (STDCALL *guFogGenerateExp2)(GrFog_t* fogtable, float density) = nullptr;
  void  (STDCALL *guFogGenerateLinear)(GrFog_t* fogtable, float nearZ, float farZ) = nullptr;

  /* hi-level texture manipulation tools. */
  bool32_t  (STDCALL *gu3dfGetInfo)(const char* filename, Gu3dfInfo* info) = nullptr;
  bool32_t  (STDCALL *gu3dfLoad)(const char* filename, Gu3dfInfo* data) = nullptr;





  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, GLIDE3XLIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", GLIDE3XLIB);
      unload();
      return false;
    }

    if(
      /* rendering functions */
      !module::load_symbol(grDrawPoint, handle, "grDrawPoint") ||
      !module::load_symbol(grDrawLine, handle, "grDrawLine") ||
      !module::load_symbol(grDrawTriangle, handle, "grDrawTriangle") ||
      !module::load_symbol(grVertexLayout, handle, "grVertexLayout") ||
      !module::load_symbol(grDrawVertexArray, handle, "grDrawVertexArray") ||
      !module::load_symbol(grDrawVertexArrayContiguous, handle, "grDrawVertexArrayContiguous") ||

      /* Antialiasing Functions */
      !module::load_symbol(grAADrawTriangle, handle, "grAADrawTriangle") ||

      /* buffer management */
      !module::load_symbol(grBufferClear, handle, "grBufferClear") ||
      !module::load_symbol(grBufferSwap, handle, "grBufferSwap") ||
      !module::load_symbol(grRenderBuffer, handle, "grRenderBuffer") ||

      /* error management */
      !module::load_symbol(grErrorSetCallback, handle, "grErrorSetCallback") ||

      /* SST routines */
      !module::load_symbol(grFinish, handle, "grFinish") ||
      !module::load_symbol(grFlush, handle, "grFlush") ||
      !module::load_symbol(grSstWinOpen, handle, "grSstWinOpen") ||
      !module::load_symbol(grSstWinClose, handle, "grSstWinClose") ||
      !module::load_symbol(grSelectContext, handle, "grSelectContext") ||
      !module::load_symbol(grSstOrigin, handle, "grSstOrigin") ||
      !module::load_symbol(grSstSelect, handle, "grSstSelect") ||

      /* Glide configuration and special effect maintenance functions */
      !module::load_symbol(grAlphaBlendFunction, handle, "grAlphaBlendFunction") ||
      !module::load_symbol(grAlphaCombine, handle, "grAlphaCombine") ||
      !module::load_symbol(grAlphaControlsITRGBLighting, handle, "grAlphaControlsITRGBLighting") ||
      !module::load_symbol(grAlphaTestFunction, handle, "grAlphaTestFunction") ||
      !module::load_symbol(grAlphaTestReferenceValue, handle, "grAlphaTestReferenceValue") ||
      !module::load_symbol(grChromakeyMode, handle, "grChromakeyMode") ||
      !module::load_symbol(grChromakeyValue, handle, "grChromakeyValue") ||
      !module::load_symbol(grClipWindow, handle, "grClipWindow") ||
      !module::load_symbol(grColorCombine, handle, "grColorCombine") ||
      !module::load_symbol(grColorMask, handle, "grColorMask") ||
      !module::load_symbol(grCullMode, handle, "grCullMode") ||
      !module::load_symbol(grConstantColorValue, handle, "grConstantColorValue") ||
      !module::load_symbol(grDepthBiasLevel, handle, "grDepthBiasLevel") ||
      !module::load_symbol(grDepthBufferFunction, handle, "grDepthBufferFunction") ||
      !module::load_symbol(grDepthBufferMode, handle, "grDepthBufferMode") ||
      !module::load_symbol(grDepthMask, handle, "grDepthMask") ||
      !module::load_symbol(grDisableAllEffects, handle, "grDisableAllEffects") ||
      !module::load_symbol(grDitherMode, handle, "grDitherMode") ||
      !module::load_symbol(grFogColorValue, handle, "grFogColorValue") ||
      !module::load_symbol(grFogMode, handle, "grFogMode") ||
      !module::load_symbol(grFogTable, handle, "grFogTable") ||
      !module::load_symbol(grLoadGammaTable, handle, "grLoadGammaTable") ||
      !module::load_symbol(grSplash, handle, "grSplash") ||
      !module::load_symbol(grGet, handle, "grGet") ||
      !module::load_symbol(grGetString, handle, "grGetString") ||
      !module::load_symbol(grQueryResolutions, handle, "grQueryResolutions") ||
      !module::load_symbol(grReset, handle, "grReset") ||
      !module::load_symbol(grGetProcAddress, handle, "grGetProcAddress") ||
      !module::load_symbol(grEnable, handle, "grEnable") ||
      !module::load_symbol(grDisable, handle, "grDisable") ||
      !module::load_symbol(grCoordinateSpace, handle, "grCoordinateSpace") ||
      !module::load_symbol(grDepthRange, handle, "grDepthRange") ||
      !module::load_symbol(grViewport, handle, "grViewport") ||

      /* texture mapping control functions */
      !module::load_symbol(grTexCalcMemRequired, handle, "grTexCalcMemRequired") ||
      !module::load_symbol(grTexTextureMemRequired, handle, "grTexTextureMemRequired") ||
      !module::load_symbol(grTexMinAddress, handle, "grTexMinAddress") ||
      !module::load_symbol(grTexMaxAddress, handle, "grTexMaxAddress") ||
      !module::load_symbol(grTexNCCTable, handle, "grTexNCCTable") ||
      !module::load_symbol(grTexSource, handle, "grTexSource") ||
      !module::load_symbol(grTexClampMode, handle, "grTexClampMode") ||
      !module::load_symbol(grTexCombine, handle, "grTexCombine") ||
      !module::load_symbol(grTexDetailControl, handle, "grTexDetailControl") ||
      !module::load_symbol(grTexFilterMode, handle, "grTexFilterMode") ||
      !module::load_symbol(grTexLodBiasValue, handle, "grTexLodBiasValue") ||
      !module::load_symbol(grTexDownloadMipMap, handle, "grTexDownloadMipMap") ||
      !module::load_symbol(grTexDownloadMipMapLevel, handle, "grTexDownloadMipMapLevel") ||
      !module::load_symbol(grTexDownloadMipMapLevelPartial, handle, "grTexDownloadMipMapLevelPartial") ||
      !module::load_symbol(grTexDownloadTable, handle, "grTexDownloadTable") ||
      !module::load_symbol(grTexDownloadTablePartial, handle, "grTexDownloadTablePartial") ||
      !module::load_symbol(grTexMipMapMode, handle, "grTexMipMapMode") ||
      !module::load_symbol(grTexMultibase, handle, "grTexMultibase") ||
      !module::load_symbol(grTexMultibaseAddress, handle, "grTexMultibaseAddress") ||

      /* linear frame buffer functions */
      !module::load_symbol(grLfbLock, handle, "grLfbLock") ||
      !module::load_symbol(grLfbUnlock, handle, "grLfbUnlock") ||
      !module::load_symbol(grLfbConstantAlpha, handle, "grLfbConstantAlpha") ||
      !module::load_symbol(grLfbConstantDepth, handle, "grLfbConstantDepth") ||
      !module::load_symbol(grLfbWriteColorSwizzle, handle, "grLfbWriteColorSwizzle") ||
      !module::load_symbol(grLfbWriteColorFormat, handle, "grLfbWriteColorFormat") ||
      !module::load_symbol(grLfbWriteRegion, handle, "grLfbWriteRegion") ||
      !module::load_symbol(grLfbReadRegion, handle, "grLfbReadRegion") ||

      /* glide management functions */
      !module::load_symbol(grGlideInit, handle, "grGlideInit") ||
      !module::load_symbol(grGlideShutdown, handle, "grGlideShutdown") ||
      !module::load_symbol(grGlideGetState, handle, "grGlideGetState") ||
      !module::load_symbol(grGlideSetState, handle, "grGlideSetState") ||
      !module::load_symbol(grGlideGetVertexLayout, handle, "grGlideGetVertexLayout") ||
      !module::load_symbol(grGlideSetVertexLayout, handle, "grGlideSetVertexLayout") ||

      /* Gamma functions */
      !module::load_symbol(guGammaCorrectionRGB, handle, "guGammaCorrectionRGB") ||

      /* fog stuff */
      !module::load_symbol(guFogTableIndexToW, handle, "guFogTableIndexToW") ||
      !module::load_symbol(guFogGenerateExp, handle, "guFogGenerateExp") ||
      !module::load_symbol(guFogGenerateExp2, handle, "guFogGenerateExp2") ||
      !module::load_symbol(guFogGenerateLinear, handle, "guFogGenerateLinear") ||

      /* hi-level texture manipulation tools. */
      !module::load_symbol(gu3dfGetInfo, handle, "gu3dfGetInfo") ||
      !module::load_symbol(gu3dfLoad, handle, "gu3dfLoad"))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", GLIDE3XLIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    /* rendering functions */
    grDrawPoint = nullptr;
    grDrawLine = nullptr;
    grDrawTriangle = nullptr;
    grVertexLayout = nullptr;
    grDrawVertexArray = nullptr;
    grDrawVertexArrayContiguous = nullptr;

    /* Antialiasing Functions */
    grAADrawTriangle = nullptr;

    /* buffer management */
    grBufferClear = nullptr;
    grBufferSwap = nullptr;
    grRenderBuffer = nullptr;

    /* error management */
    grErrorSetCallback = nullptr;

    /* SST routines */
    grFinish = nullptr;
    grFlush = nullptr;
    grSstWinOpen = nullptr;
    grSstWinClose = nullptr;
    grSelectContext = nullptr;
    grSstOrigin = nullptr;
    grSstSelect = nullptr;

    /* Glide configuration and special effect maintenance functions */
    grAlphaBlendFunction = nullptr;
    grAlphaCombine = nullptr;
    grAlphaControlsITRGBLighting = nullptr;
    grAlphaTestFunction = nullptr;
    grAlphaTestReferenceValue = nullptr;
    grChromakeyMode = nullptr;
    grChromakeyValue = nullptr;
    grClipWindow = nullptr;
    grColorCombine = nullptr;
    grColorMask = nullptr;
    grCullMode = nullptr;
    grConstantColorValue = nullptr;
    grDepthBiasLevel = nullptr;
    grDepthBufferFunction = nullptr;
    grDepthBufferMode = nullptr;
    grDepthMask = nullptr;
    grDisableAllEffects = nullptr;
    grDitherMode = nullptr;
    grFogColorValue = nullptr;
    grFogMode = nullptr;
    grFogTable = nullptr;
    grLoadGammaTable = nullptr;
    grSplash = nullptr;
    grGet = nullptr;
    grGetString = nullptr;
    grQueryResolutions = nullptr;
    grReset = nullptr;
    grGetProcAddress = nullptr;
    grEnable = nullptr;
    grDisable = nullptr;
    grCoordinateSpace = nullptr;
    grDepthRange = nullptr;
    grViewport = nullptr;

    /* texture mapping control functions */
    grTexCalcMemRequired = nullptr;
    grTexTextureMemRequired = nullptr;
    grTexMinAddress = nullptr;
    grTexMaxAddress = nullptr;
    grTexNCCTable = nullptr;
    grTexSource = nullptr;
    grTexClampMode = nullptr;
    grTexCombine = nullptr;
    grTexDetailControl = nullptr;
    grTexFilterMode = nullptr;
    grTexLodBiasValue = nullptr;
    grTexDownloadMipMap = nullptr;
    grTexDownloadMipMapLevel = nullptr;
    grTexDownloadMipMapLevelPartial = nullptr;
    grTexDownloadTable = nullptr;
    grTexDownloadTablePartial = nullptr;
    grTexMipMapMode = nullptr;
    grTexMultibase = nullptr;
    grTexMultibaseAddress = nullptr;

    /* linear frame buffer functions */
    grLfbLock = nullptr;
    grLfbUnlock = nullptr;
    grLfbConstantAlpha = nullptr;
    grLfbConstantDepth = nullptr;
    grLfbWriteColorSwizzle = nullptr;
    grLfbWriteColorFormat = nullptr;
    grLfbWriteRegion = nullptr;
    grLfbReadRegion = nullptr;

    /* glide management functions */
    grGlideInit = nullptr;
    grGlideShutdown = nullptr;
    grGlideGetState = nullptr;
    grGlideSetState = nullptr;
    grGlideGetVertexLayout = nullptr;
    grGlideSetVertexLayout = nullptr;

    /* Gamma functions */
    guGammaCorrectionRGB = nullptr;

    /* fog stuff */
    guFogTableIndexToW = nullptr;
    guFogGenerateExp = nullptr;
    guFogGenerateExp2 = nullptr;
    guFogGenerateLinear = nullptr;

    /* hi-level texture manipulation tools. */
    gu3dfGetInfo = nullptr;
    gu3dfLoad = nullptr;

    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", GLIDE3XLIB);
      return false;
    }
    return true;
  }
}
