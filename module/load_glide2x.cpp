#include "load_glide2x.h"

// System
#include <stdio.h>

#ifndef GLIDELIB
# ifdef __unix__
  constexpr const char* const GLIDE2XLIB = "libglide2x.so";
# elif defined(_WIN32) || defined(__CYGWIN__)
  constexpr const char* const GLIDELIB = "glide2x.dll";
# endif
#endif

namespace glide
{
  void (STDCALL *grDrawLine)(const GrVertex *v1, const GrVertex *v2) = nullptr;
  void (STDCALL *grDrawPlanarPolygon)(int nverts, const int ilist[], const GrVertex vlist[]) = nullptr;
  void (STDCALL *grDrawPlanarPolygonVertexList)(int nverts, const GrVertex vlist[]) = nullptr;
  void (STDCALL *grDrawPoint)(const GrVertex *pt) = nullptr;
  void (STDCALL *grDrawPolygon)(int nverts, const int ilist[], const GrVertex vlist[]) = nullptr;
  void (STDCALL *grDrawPolygonVertexList)(int nverts, const GrVertex vlist[]) = nullptr;
  void (STDCALL *grDrawTriangle)(const GrVertex *a, const GrVertex *b, const GrVertex *c) = nullptr;
  void (STDCALL *grBufferClear)(GrColor_t color, GrAlpha_t alpha, uint16_t depth) = nullptr;
  int (STDCALL *grBufferNumPending)(void) = nullptr;
  void (STDCALL *grBufferSwap)(int swap_interval) = nullptr;
  void (STDCALL *grRenderBuffer)(GrBuffer_t buffer) = nullptr;
  void (STDCALL *grErrorSetCallback)(GrErrorCallbackFnc_t fnc) = nullptr;
  void (STDCALL *grFinish)(void) = nullptr;
  void (STDCALL *grFlush)(void) = nullptr;
  void (STDCALL *grSstIdle)(void) = nullptr;
  uint32_t (STDCALL *grSstVideoLine)(void) = nullptr;
  FxBool (STDCALL *grSstVRetraceOn)(void) = nullptr;
  FxBool (STDCALL *grSstIsBusy)(void) = nullptr;
  FxBool (STDCALL *grSstWinOpen)(uint32_t hWnd, GrScreenResolution_t screen_resolution, GrScreenRefresh_t refresh_rate, GrColorFormat_t color_format, GrOriginLocation_t origin_location, int nColBuffers, int nAuxBuffers) = nullptr;
  void (STDCALL *grSstWinClose)(void) = nullptr;
  FxBool (STDCALL *grSstControl)(uint32_t code) = nullptr;
  FxBool (STDCALL *grSstQueryHardware)(GrHwConfiguration *hwconfig) = nullptr;
  FxBool (STDCALL *grSstQueryBoards)(GrHwConfiguration *hwconfig) = nullptr;
  void (STDCALL *grSstOrigin)(GrOriginLocation_t origin) = nullptr;
  void (STDCALL *grSstSelect)(int which_sst) = nullptr;
  int (STDCALL *grSstScreenHeight)(void) = nullptr;
  int (STDCALL *grSstScreenWidth)(void) = nullptr;
  uint32_t (STDCALL *grSstStatus)(void) = nullptr;
  void (STDCALL *grSstPerfStats)(GrSstPerfStats_t *pStats) = nullptr;
  void (STDCALL *grSstResetPerfStats)(void) = nullptr;
  void (STDCALL *grResetTriStats)() = nullptr;
  void (STDCALL *grTriStats)(uint32_t *trisProcessed, uint32_t *trisDrawn) = nullptr;
  void (STDCALL *grAlphaBlendFunction)(GrAlphaBlendFnc_t rgb_sf, GrAlphaBlendFnc_t rgb_df, GrAlphaBlendFnc_t alpha_sf, GrAlphaBlendFnc_t alpha_df) = nullptr;
  void (STDCALL *grAlphaCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, FxBool invert) = nullptr;
  void (STDCALL *grAlphaControlsITRGBLighting)(FxBool enable) = nullptr;
  void (STDCALL *grAlphaTestFunction)(GrCmpFnc_t function) = nullptr;
  void (STDCALL *grAlphaTestReferenceValue)(GrAlpha_t value) = nullptr;
  void (STDCALL *grChromakeyMode)(GrChromakeyMode_t mode) = nullptr;
  void (STDCALL *grChromakeyValue)(GrColor_t value) = nullptr;
  void (STDCALL *grClipWindow)(int minx, int miny, int maxx, int maxy) = nullptr;
  void (STDCALL *grColorCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, FxBool invert) = nullptr;
  void (STDCALL *grColorMask)(FxBool rgb, FxBool a) = nullptr;
  void (STDCALL *grCullMode)(GrCullMode_t mode) = nullptr;
  void (STDCALL *grConstantColorValue)(GrColor_t value) = nullptr;
  void (STDCALL *grConstantColorValue4)(float a, float r, float g, float b) = nullptr;
  void (STDCALL *grDepthBiasLevel)(int16_t level) = nullptr;
  void (STDCALL *grDepthBufferFunction)(GrCmpFnc_t function) = nullptr;
  void (STDCALL *grDepthBufferMode)(GrDepthBufferMode_t mode) = nullptr;
  void (STDCALL *grDepthMask)(FxBool mask) = nullptr;
  void (STDCALL *grDisableAllEffects)(void) = nullptr;
  void (STDCALL *grDitherMode)(GrDitherMode_t mode) = nullptr;
  void (STDCALL *grFogColorValue)(GrColor_t fogcolor) = nullptr;
  void (STDCALL *grFogMode)(GrFogMode_t mode) = nullptr;
  void (STDCALL *grFogTable)(const GrFog_t ft[GR_FOG_TABLE_SIZE]) = nullptr;
  void (STDCALL *grGammaCorrectionValue)(float value) = nullptr;
  void (STDCALL *grSplash)(float x, float y, float width, float height, uint32_t frame) = nullptr;
  uint32_t (STDCALL *grTexCalcMemRequired)(GrLOD_t lodmin, GrLOD_t lodmax, GrAspectRatio_t aspect, GrTextureFormat_t fmt) = nullptr;
  uint32_t (STDCALL *grTexTextureMemRequired)(uint32_t evenOdd, GrTexInfo *info) = nullptr;
  uint32_t (STDCALL *grTexMinAddress)(GrChipID_t tmu) = nullptr;
  uint32_t (STDCALL *grTexMaxAddress)(GrChipID_t tmu) = nullptr;
  void (STDCALL *grTexNCCTable)(GrChipID_t tmu, GrNCCTable_t table) = nullptr;
  void (STDCALL *grTexSource)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info) = nullptr;
  void (STDCALL *grTexClampMode)(GrChipID_t tmu, GrTextureClampMode_t s_clampmode, GrTextureClampMode_t t_clampmode) = nullptr;
  void (STDCALL *grTexCombine)(GrChipID_t tmu, GrCombineFunction_t rgb_function, GrCombineFactor_t rgb_factor, GrCombineFunction_t alpha_function, GrCombineFactor_t alpha_factor, FxBool rgb_invert, FxBool alpha_invert) = nullptr;
  void (STDCALL *grTexCombineFunction)(GrChipID_t tmu, GrTextureCombineFnc_t fnc) = nullptr;
  void (STDCALL *grTexDetailControl)(GrChipID_t tmu, int lod_bias, uint8_t detail_scale, float detail_max) = nullptr;
  void (STDCALL *grTexFilterMode)(GrChipID_t tmu, GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode) = nullptr;
  void (STDCALL *grTexLodBiasValue)(GrChipID_t tmu, float bias) = nullptr;
  void (STDCALL *grTexDownloadMipMap)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info) = nullptr;
  void (STDCALL *grTexDownloadMipMapLevel)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void *data) = nullptr;
  void (STDCALL *grTexDownloadMipMapLevelPartial)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void *data, int start, int end) = nullptr;
  void (STDCALL *ConvertAndDownloadRle)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, uint8_t *bm_data, long bm_h, uint32_t u0, uint32_t v0, uint32_t width, uint32_t height, uint32_t dest_width, uint32_t dest_height, uint16_t *tlut) = nullptr;
  void (STDCALL *grCheckForRoom)(int32_t n) = nullptr;
  void (STDCALL *grTexDownloadTable)(GrChipID_t tmu, GrTexTable_t type, void *data) = nullptr;
  void (STDCALL *grTexDownloadTablePartial)(GrChipID_t tmu, GrTexTable_t type, void *data, int start, int end) = nullptr;
  void (STDCALL *grTexMipMapMode)(GrChipID_t tmu, GrMipMapMode_t mode, FxBool lodBlend) = nullptr;
  void (STDCALL *grTexMultibase)(GrChipID_t tmu, FxBool enable) = nullptr;
  void (STDCALL *grTexMultibaseAddress)(GrChipID_t tmu, GrTexBaseRange_t range, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info) = nullptr;
  FxBool (STDCALL *grLfbLock)(GrLock_t type, GrBuffer_t buffer, GrLfbWriteMode_t writeMode, GrOriginLocation_t origin, FxBool pixelPipeline, GrLfbInfo_t *info) = nullptr;
  FxBool (STDCALL *grLfbUnlock)(GrLock_t type, GrBuffer_t buffer) = nullptr;
  void (STDCALL *grLfbConstantAlpha)(GrAlpha_t alpha) = nullptr;
  void (STDCALL *grLfbConstantDepth)(uint16_t depth) = nullptr;
  void (STDCALL *grLfbWriteColorSwizzle)(FxBool swizzleBytes, FxBool swapWords) = nullptr;
  void (STDCALL *grLfbWriteColorFormat)(GrColorFormat_t colorFormat) = nullptr;
  FxBool (STDCALL *grLfbWriteRegion)(GrBuffer_t dst_buffer, uint32_t dst_x, uint32_t dst_y, GrLfbSrcFmt_t src_format, uint32_t src_width, uint32_t src_height, int32_t src_stride, void *src_data) = nullptr;
  FxBool (STDCALL *grLfbReadRegion)(GrBuffer_t src_buffer, uint32_t src_x, uint32_t src_y, uint32_t src_width, uint32_t src_height, uint32_t dst_stride, void *dst_data) = nullptr;
  void (STDCALL *grAADrawLine)(const GrVertex *v1, const GrVertex *v2) = nullptr;
  void (STDCALL *grAADrawPoint)(const GrVertex *pt) = nullptr;
  void (STDCALL *grAADrawPolygon)(const int nverts, const int ilist[], const GrVertex vlist[]) = nullptr;
  void (STDCALL *grAADrawPolygonVertexList)(const int nverts, const GrVertex vlist[]) = nullptr;
  void (STDCALL *grAADrawTriangle)(const GrVertex *a, const GrVertex *b, const GrVertex *c, FxBool ab_antialias, FxBool bc_antialias, FxBool ca_antialias) = nullptr;
  void (STDCALL *grGlideInit)(void) = nullptr;
  void (STDCALL *grGlideShutdown)(void) = nullptr;
  void (STDCALL *grGlideGetVersion)(char version[80]) = nullptr;
  void (STDCALL *grGlideGetState)(GrState *state) = nullptr;
  void (STDCALL *grGlideSetState)(const GrState *state) = nullptr;
  void (STDCALL *grGlideShamelessPlug)(const FxBool on) = nullptr;
  void (STDCALL *grHints)(GrHint_t hintType, uint32_t hintMask) = nullptr;
  GrMipMapId_t (STDCALL *guTexAllocateMemory)(GrChipID_t tmu, uint8_t odd_even_mask, int width, int height, GrTextureFormat_t fmt, GrMipMapMode_t mm_mode, GrLOD_t smallest_lod, GrLOD_t largest_lod, GrAspectRatio_t aspect, GrTextureClampMode_t s_clamp_mode, GrTextureClampMode_t t_clamp_mode, GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode, float lod_bias, FxBool trilinear) = nullptr;
  FxBool (STDCALL *guTexChangeAttributes)(GrMipMapId_t mmid, int width, int height, GrTextureFormat_t fmt, GrMipMapMode_t mm_mode, GrLOD_t smallest_lod, GrLOD_t largest_lod, GrAspectRatio_t aspect, GrTextureClampMode_t s_clamp_mode, GrTextureClampMode_t t_clamp_mode, GrTextureFilterMode_t minFilterMode, GrTextureFilterMode_t magFilterMode) = nullptr;
  void (STDCALL *guTexCombineFunction)(GrChipID_t tmu, GrTextureCombineFnc_t fnc) = nullptr;
  GrMipMapId_t (STDCALL *guTexGetCurrentMipMap)(GrChipID_t tmu) = nullptr;
  GrMipMapInfo* (STDCALL *guTexGetMipMapInfo)(GrMipMapId_t mmid) = nullptr;
  uint32_t (STDCALL *guTexMemQueryAvail)(GrChipID_t tmu) = nullptr;
  void (STDCALL *guTexMemReset)(void) = nullptr;
  void (STDCALL *guTexDownloadMipMap)(GrMipMapId_t mmid, const void *src, const GuNccTable *table) = nullptr;
  void (STDCALL *guTexDownloadMipMapLevel)(GrMipMapId_t mmid, GrLOD_t lod, const void **src) = nullptr;
  void (STDCALL *guTexSource)(GrMipMapId_t id) = nullptr;
  void (STDCALL *guAADrawTriangleWithClip)(const GrVertex *a, const GrVertex *b, const GrVertex *c) = nullptr;
  void (STDCALL *guDrawTriangleWithClip)(const GrVertex *a, const GrVertex *b, const GrVertex *c) = nullptr;
  void (STDCALL *guDrawPolygonVertexListWithClip)(int nverts, const GrVertex vlist[]) = nullptr;
  void (STDCALL *guAlphaSource)(GrAlphaSource_t mode) = nullptr;
  void (STDCALL *guColorCombineFunction)(GrColorCombineFnc_t fnc) = nullptr;
  void (STDCALL *guFbReadRegion)(const int src_x, const int src_y, const int w, const int h, const void *dst, const int strideInBytes) = nullptr;
  int (STDCALL *guEncodeRLE16)(void *dst, void *src, uint32_t width, uint32_t height) = nullptr;
  uint16_t * (STDCALL *guTexCreateColorMipMap)(void) = nullptr;
  void (STDCALL *guMovieStart)(void) = nullptr;
  void (STDCALL *guMovieStop)(void) = nullptr;
  void (STDCALL *guMovieSetName)(const char *name) = nullptr;
  float (STDCALL *guFogTableIndexToW)(int i) = nullptr;
  void (STDCALL *guFogGenerateExp)(GrFog_t fogtable[GR_FOG_TABLE_SIZE], float density) = nullptr;
  void (STDCALL *guFogGenerateExp2)(GrFog_t fogtable[GR_FOG_TABLE_SIZE], float density) = nullptr;
  void (STDCALL *guFogGenerateLinear)(GrFog_t fogtable[GR_FOG_TABLE_SIZE], float nearZ, float farZ) = nullptr;
  uint32_t (STDCALL *guEndianSwapWords)(uint32_t value) = nullptr;
  uint16_t (STDCALL *guEndianSwapBytes)(uint16_t value) = nullptr;
  FxBool (STDCALL *gu3dfGetInfo)(const char *filename, Gu3dfInfo *info) = nullptr;
  FxBool (STDCALL *gu3dfLoad)(const char *filename, Gu3dfInfo *data) = nullptr;

  static module::handle_t handle = nullptr;

  bool load(void)
  {
    if(handle != nullptr)
      return true;

    // Load the library
    if (!module::load(handle, GLIDE2XLIB, MODF_LAZY | MODF_GLOBAL))
    {
      fprintf(stderr, "Library Load Failed: %s\n", GLIDE2XLIB);
      unload();
      return false;
    }

    if(
  #if defined(WIN32)
    !module::load_symbol(ConvertAndDownloadRle, handle, "ConvertAndDownloadRle", 64) ||
  #endif
    !module::load_symbol(grAADrawLine, handle, "grAADrawLine", 8) ||
    !module::load_symbol(grAADrawPoint, handle, "grAADrawPoint", 4) ||
    !module::load_symbol(grAADrawPolygon, handle, "grAADrawPolygon", 12) ||
    !module::load_symbol(grAADrawPolygonVertexList, handle, "grAADrawPolygonVertexList", 8) ||
    !module::load_symbol(grAADrawTriangle, handle, "grAADrawTriangle", 24) ||
    !module::load_symbol(grAlphaBlendFunction, handle, "grAlphaBlendFunction", 16) ||
    !module::load_symbol(grAlphaCombine, handle, "grAlphaCombine", 20) ||
    !module::load_symbol(grAlphaControlsITRGBLighting, handle, "grAlphaControlsITRGBLighting", 4) ||
    !module::load_symbol(grAlphaTestFunction, handle, "grAlphaTestFunction", 4) ||
    !module::load_symbol(grAlphaTestReferenceValue, handle, "grAlphaTestReferenceValue", 4) ||
    !module::load_symbol(grBufferClear, handle, "grBufferClear", 12) ||
    !module::load_symbol(grBufferNumPending, handle, "grBufferNumPending", 0) ||
    !module::load_symbol(grBufferSwap, handle, "grBufferSwap", 4) ||
    !module::load_symbol(grCheckForRoom, handle, "grCheckForRoom", 4) ||
    !module::load_symbol(grChromakeyMode, handle, "grChromakeyMode", 4) ||
    !module::load_symbol(grChromakeyValue, handle, "grChromakeyValue", 4) ||
    !module::load_symbol(grClipWindow, handle, "grClipWindow", 16) ||
    !module::load_symbol(grColorCombine, handle, "grColorCombine", 20) ||
    !module::load_symbol(grColorMask, handle, "grColorMask", 8) ||
    !module::load_symbol(grConstantColorValue, handle, "grConstantColorValue", 4) ||
    !module::load_symbol(grConstantColorValue4, handle, "grConstantColorValue4", 16) ||
    !module::load_symbol(grCullMode, handle, "grCullMode", 4) ||
    !module::load_symbol(grDepthBiasLevel, handle, "grDepthBiasLevel", 4) ||
    !module::load_symbol(grDepthBufferFunction, handle, "grDepthBufferFunction", 4) ||
    !module::load_symbol(grDepthBufferMode, handle, "grDepthBufferMode", 4) ||
    !module::load_symbol(grDepthMask, handle, "grDepthMask", 4) ||
    !module::load_symbol(grDisableAllEffects, handle, "grDisableAllEffects", 0) ||
    !module::load_symbol(grDitherMode, handle, "grDitherMode", 4) ||
    !module::load_symbol(grDrawLine, handle, "grDrawLine", 8) ||
    !module::load_symbol(grDrawPlanarPolygon, handle, "grDrawPlanarPolygon", 12) ||
    !module::load_symbol(grDrawPlanarPolygonVertexList, handle, "grDrawPlanarPolygonVertexList", 8) ||
    !module::load_symbol(grDrawPoint, handle, "grDrawPoint", 4) ||
    !module::load_symbol(grDrawPolygon, handle, "grDrawPolygon", 12) ||
    !module::load_symbol(grDrawPolygonVertexList, handle, "grDrawPolygonVertexList", 8) ||
    !module::load_symbol(grDrawTriangle, handle, "grDrawTriangle", 12) ||
    !module::load_symbol(grErrorSetCallback, handle, "grErrorSetCallback", 4) ||
    !module::load_symbol(grFogColorValue, handle, "grFogColorValue", 4) ||
    !module::load_symbol(grFogMode, handle, "grFogMode", 4) ||
    !module::load_symbol(grFogTable, handle, "grFogTable", 4) ||
    !module::load_symbol(grGammaCorrectionValue, handle, "grGammaCorrectionValue", 4) ||
    !module::load_symbol(grGlideGetState, handle, "grGlideGetState", 4) ||
    !module::load_symbol(grGlideGetVersion, handle, "grGlideGetVersion", 4) ||
    !module::load_symbol(grGlideInit, handle, "grGlideInit", 0) ||
    !module::load_symbol(grGlideSetState, handle, "grGlideSetState", 4) ||
    !module::load_symbol(grGlideShamelessPlug, handle, "grGlideShamelessPlug", 4) ||
    !module::load_symbol(grGlideShutdown, handle, "grGlideShutdown", 0) ||
    !module::load_symbol(grHints, handle, "grHints", 8) ||
    !module::load_symbol(grLfbConstantAlpha, handle, "grLfbConstantAlpha", 4) ||
    !module::load_symbol(grLfbConstantDepth, handle, "grLfbConstantDepth", 4) ||
    !module::load_symbol(grLfbLock, handle, "grLfbLock", 24) ||
    !module::load_symbol(grLfbReadRegion, handle, "grLfbReadRegion", 28) ||
    !module::load_symbol(grLfbUnlock, handle, "grLfbUnlock", 8) ||
    !module::load_symbol(grLfbWriteColorFormat, handle, "grLfbWriteColorFormat", 4) ||
    !module::load_symbol(grLfbWriteColorSwizzle, handle, "grLfbWriteColorSwizzle", 8) ||
    !module::load_symbol(grLfbWriteRegion, handle, "grLfbWriteRegion", 32) ||
    !module::load_symbol(grRenderBuffer, handle, "grRenderBuffer", 4) ||
    !module::load_symbol(grResetTriStats, handle, "grResetTriStats", 0) ||
    !module::load_symbol(grSplash, handle, "grSplash", 20) ||
    !module::load_symbol(grSstControl, handle, "grSstControl", 4) ||
    !module::load_symbol(grSstIdle, handle, "grSstIdle", 0) ||
    !module::load_symbol(grSstIsBusy, handle, "grSstIsBusy", 0) ||
    !module::load_symbol(grSstOrigin, handle, "grSstOrigin", 4) ||
    !module::load_symbol(grSstPerfStats, handle, "grSstPerfStats", 4) ||
    !module::load_symbol(grSstQueryBoards, handle, "grSstQueryBoards", 4) ||
    !module::load_symbol(grSstQueryHardware, handle, "grSstQueryHardware", 4) ||
    !module::load_symbol(grSstResetPerfStats, handle, "grSstResetPerfStats", 0) ||
    !module::load_symbol(grSstScreenHeight, handle, "grSstScreenHeight", 0) ||
    !module::load_symbol(grSstScreenWidth, handle, "grSstScreenWidth", 0) ||
    !module::load_symbol(grSstSelect, handle, "grSstSelect", 4) ||
    !module::load_symbol(grSstStatus, handle, "grSstStatus", 0) ||
    !module::load_symbol(grSstVRetraceOn, handle, "grSstVRetraceOn", 0) ||
    !module::load_symbol(grSstVideoLine, handle, "grSstVideoLine", 0) ||
    !module::load_symbol(grSstWinClose, handle, "grSstWinClose", 0) ||
    !module::load_symbol(grSstWinOpen, handle, "grSstWinOpen", 28) ||
    !module::load_symbol(grTexCalcMemRequired, handle, "grTexCalcMemRequired", 16) ||
    !module::load_symbol(grTexClampMode, handle, "grTexClampMode", 12) ||
    !module::load_symbol(grTexCombine, handle, "grTexCombine", 28) ||
    !module::load_symbol(grTexCombineFunction, handle, "grTexCombineFunction", 8) ||
    !module::load_symbol(grTexDetailControl, handle, "grTexDetailControl", 16) ||
    !module::load_symbol(grTexDownloadMipMap, handle, "grTexDownloadMipMap", 16) ||
    !module::load_symbol(grTexDownloadMipMapLevel, handle, "grTexDownloadMipMapLevel", 32) ||
    !module::load_symbol(grTexDownloadMipMapLevelPartial, handle, "grTexDownloadMipMapLevelPartial", 40) ||
    !module::load_symbol(grTexDownloadTable, handle, "grTexDownloadTable", 12) ||
    !module::load_symbol(grTexDownloadTablePartial, handle, "grTexDownloadTablePartial", 20) ||
    !module::load_symbol(grTexFilterMode, handle, "grTexFilterMode", 12) ||
    !module::load_symbol(grTexLodBiasValue, handle, "grTexLodBiasValue", 8) ||
    !module::load_symbol(grTexMaxAddress, handle, "grTexMaxAddress", 4) ||
    !module::load_symbol(grTexMinAddress, handle, "grTexMinAddress", 4) ||
    !module::load_symbol(grTexMipMapMode, handle, "grTexMipMapMode", 12) ||
    !module::load_symbol(grTexMultibase, handle, "grTexMultibase", 8) ||
    !module::load_symbol(grTexMultibaseAddress, handle, "grTexMultibaseAddress", 20) ||
    !module::load_symbol(grTexNCCTable, handle, "grTexNCCTable", 8) ||
    !module::load_symbol(grTexSource, handle, "grTexSource", 16) ||
    !module::load_symbol(grTexTextureMemRequired, handle, "grTexTextureMemRequired", 8) ||
    !module::load_symbol(grTriStats, handle, "grTriStats", 8) ||

    !module::load_symbol(gu3dfGetInfo, handle, "gu3dfGetInfo", 8) ||
    !module::load_symbol(gu3dfLoad, handle, "gu3dfLoad", 8) ||
    !module::load_symbol(guAADrawTriangleWithClip, handle, "guAADrawTriangleWithClip", 12) ||
    !module::load_symbol(guAlphaSource, handle, "guAlphaSource", 4) ||
    !module::load_symbol(guColorCombineFunction, handle, "guColorCombineFunction", 4) ||
    !module::load_symbol(guDrawPolygonVertexListWithClip, handle, "guDrawPolygonVertexListWithClip", 8) ||
    !module::load_symbol(guDrawTriangleWithClip, handle, "guDrawTriangleWithClip", 12) ||
    !module::load_symbol(guEncodeRLE16, handle, "guEncodeRLE16", 16) ||
    !module::load_symbol(guEndianSwapBytes, handle, "guEndianSwapBytes", 4) ||
    !module::load_symbol(guEndianSwapWords, handle, "guEndianSwapWords", 4) ||
    !module::load_symbol(guFogGenerateExp, handle, "guFogGenerateExp", 8) ||
    !module::load_symbol(guFogGenerateExp2, handle, "guFogGenerateExp2", 8) ||
    !module::load_symbol(guFogGenerateLinear, handle, "guFogGenerateLinear", 12) ||
    !module::load_symbol(guFogTableIndexToW, handle, "guFogTableIndexToW", 4) ||

    !module::load_symbol(guTexAllocateMemory, handle, "guTexAllocateMemory", 60) ||
    !module::load_symbol(guTexChangeAttributes, handle, "guTexChangeAttributes", 48) ||
    !module::load_symbol(guTexCombineFunction, handle, "guTexCombineFunction", 8) ||
    !module::load_symbol(guTexCreateColorMipMap, handle, "guTexCreateColorMipMap", 0) ||
    !module::load_symbol(guTexDownloadMipMap, handle, "guTexDownloadMipMap", 12) ||
    !module::load_symbol(guTexDownloadMipMapLevel, handle, "guTexDownloadMipMapLevel", 12) ||
    !module::load_symbol(guTexGetCurrentMipMap, handle, "guTexGetCurrentMipMap", 4) ||
    !module::load_symbol(guTexGetMipMapInfo, handle, "guTexGetMipMapInfo", 4) ||
    !module::load_symbol(guTexMemQueryAvail, handle, "guTexMemQueryAvail", 4) ||
    !module::load_symbol(guTexMemReset, handle, "guTexMemReset", 0) ||
    !module::load_symbol(guTexSource, handle, "guTexSource", 4))
    {
      fprintf(stderr, "Library Symbol Resolve Error: %s\n", GLIDE2XLIB);
      unload();
      return false;
    }
    return true;
  }

  bool unload(void)
  {
    grDrawLine = nullptr;
    grDrawPlanarPolygon = nullptr;
    grDrawPlanarPolygonVertexList = nullptr;
    grDrawPoint = nullptr;
    grDrawPolygon = nullptr;
    grDrawPolygonVertexList = nullptr;
    grDrawTriangle = nullptr;
    grBufferClear = nullptr;
    grBufferNumPending = nullptr;
    grBufferSwap = nullptr;
    grRenderBuffer = nullptr;
    grErrorSetCallback = nullptr;
    grFinish = nullptr;
    grFlush = nullptr;
    grSstIdle = nullptr;
    grSstVideoLine = nullptr;
    grSstVRetraceOn = nullptr;
    grSstIsBusy = nullptr;
    grSstWinOpen = nullptr;
    grSstWinClose = nullptr;
    grSstControl = nullptr;
    grSstQueryHardware = nullptr;
    grSstQueryBoards = nullptr;
    grSstOrigin = nullptr;
    grSstSelect = nullptr;
    grSstScreenHeight = nullptr;
    grSstScreenWidth = nullptr;
    grSstStatus = nullptr;
    grSstPerfStats = nullptr;
    grSstResetPerfStats = nullptr;
    grResetTriStats = nullptr;
    grTriStats = nullptr;
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
    grConstantColorValue4 = nullptr;
    grDepthBiasLevel = nullptr;
    grDepthBufferFunction = nullptr;
    grDepthBufferMode = nullptr;
    grDepthMask = nullptr;
    grDisableAllEffects = nullptr;
    grDitherMode = nullptr;
    grFogColorValue = nullptr;
    grFogMode = nullptr;
    grFogTable = nullptr;
    grGammaCorrectionValue = nullptr;
    grSplash = nullptr;
    grTexCalcMemRequired = nullptr;
    grTexTextureMemRequired = nullptr;
    grTexMinAddress = nullptr;
    grTexMaxAddress = nullptr;
    grTexNCCTable = nullptr;
    grTexSource = nullptr;
    grTexClampMode = nullptr;
    grTexCombine = nullptr;
    grTexCombineFunction = nullptr;
    grTexDetailControl = nullptr;
    grTexFilterMode = nullptr;
    grTexLodBiasValue = nullptr;
    grTexDownloadMipMap = nullptr;
    grTexDownloadMipMapLevel = nullptr;
    grTexDownloadMipMapLevelPartial = nullptr;
    ConvertAndDownloadRle = nullptr;
    grCheckForRoom = nullptr;
    grTexDownloadTable = nullptr;
    grTexDownloadTablePartial = nullptr;
    grTexMipMapMode = nullptr;
    grTexMultibase = nullptr;
    grTexMultibaseAddress = nullptr;
    grLfbLock = nullptr;
    grLfbUnlock = nullptr;
    grLfbConstantAlpha = nullptr;
    grLfbConstantDepth = nullptr;
    grLfbWriteColorSwizzle = nullptr;
    grLfbWriteColorFormat = nullptr;
    grLfbWriteRegion = nullptr;
    grLfbReadRegion = nullptr;
    grAADrawLine = nullptr;
    grAADrawPoint = nullptr;
    grAADrawPolygon = nullptr;
    grAADrawPolygonVertexList = nullptr;
    grAADrawTriangle = nullptr;
    grGlideInit = nullptr;
    grGlideShutdown = nullptr;
    grGlideGetVersion = nullptr;
    grGlideGetState = nullptr;
    grGlideSetState = nullptr;
    grGlideShamelessPlug = nullptr;
    grHints = nullptr;
    guTexAllocateMemory = nullptr;
    guTexChangeAttributes = nullptr;
    guTexCombineFunction = nullptr;
    guTexGetCurrentMipMap = nullptr;
    guTexGetMipMapInfo = nullptr;
    guTexMemQueryAvail = nullptr;
    guTexMemReset = nullptr;
    guTexDownloadMipMap = nullptr;
    guTexDownloadMipMapLevel = nullptr;
    guTexSource = nullptr;
    guAADrawTriangleWithClip = nullptr;
    guDrawTriangleWithClip = nullptr;
    guDrawPolygonVertexListWithClip = nullptr;
    guAlphaSource = nullptr;
    guColorCombineFunction = nullptr;
    guFbReadRegion = nullptr;
    guEncodeRLE16 = nullptr;
    guTexCreateColorMipMap = nullptr;
    guMovieStart = nullptr;
    guMovieStop = nullptr;
    guMovieSetName = nullptr;
    guFogTableIndexToW = nullptr;
    guFogGenerateExp = nullptr;
    guFogGenerateExp2 = nullptr;
    guFogGenerateLinear = nullptr;
    guEndianSwapWords = nullptr;
    guEndianSwapBytes = nullptr;
    gu3dfGetInfo = nullptr;
    gu3dfLoad = nullptr;

    if(handle != nullptr)
    {
      module::unload(handle);
      fprintf(stderr, "Library Unload Failed: %s\n", GLIDE2XLIB);
      return false;
    }
    return true;
  }
}
