#ifndef LOAD_LIB_GLIDE
#define LOAD_LIB_GLIDE

// System
#include <stdint.h>

// System copied to Project
#include "glide2x/glide.h"
#include "glide2x/glideutl.h"

// Project
#include "module.h"


namespace glide
{
  bool load(void);
  bool unload(void);

/*** rendering functions */
  extern void (STDCALL *grDrawLine)(const GrVertex *v1, const GrVertex *v2);
  extern void (STDCALL *grDrawPlanarPolygon)(int nverts, const int ilist[], const GrVertex vlist[]);
  extern void (STDCALL *grDrawPlanarPolygonVertexList)(int nverts, const GrVertex vlist[]);
  extern void (STDCALL *grDrawPoint)(const GrVertex *pt);
  extern void (STDCALL *grDrawPolygon)(int nverts, const int ilist[], const GrVertex vlist[]);
  extern void (STDCALL *grDrawPolygonVertexList)(int nverts, const GrVertex vlist[]);
  extern void (STDCALL *grDrawTriangle)(const GrVertex *a, const GrVertex *b, const GrVertex *c);

/*** buffer management */
  extern void (STDCALL *grBufferClear)(GrColor_t color, GrAlpha_t alpha, uint16_t depth);
  extern int (STDCALL *grBufferNumPending)(void);
  extern void (STDCALL *grBufferSwap)(int swap_interval);
  extern void (STDCALL *grRenderBuffer)(GrBuffer_t buffer);

/*** error management */
  typedef void (*GrErrorCallbackFnc_t)(const char *string, FxBool fatal);
  extern void (STDCALL *grErrorSetCallback)(GrErrorCallbackFnc_t fnc);

/*** SST routines */
  extern void (STDCALL *grFinish)(void);
  extern void (STDCALL *grFlush)(void);
  extern void (STDCALL *grSstIdle)(void);
  extern uint32_t (STDCALL *grSstVideoLine)(void);
  extern FxBool (STDCALL *grSstVRetraceOn)(void);
  extern FxBool (STDCALL *grSstIsBusy)(void);

  extern FxBool (STDCALL *grSstWinOpen)(uint32_t hWnd, GrScreenResolution_t screen_resolution, GrScreenRefresh_t refresh_rate, GrColorFormat_t color_format, GrOriginLocation_t origin_location, int nColBuffers, int nAuxBuffers);
  extern void (STDCALL *grSstWinClose)(void);
  extern FxBool (STDCALL *grSstControl)(uint32_t code);
  extern FxBool (STDCALL *grSstQueryHardware)(GrHwConfiguration *hwconfig);
  extern FxBool (STDCALL *grSstQueryBoards)(GrHwConfiguration *hwconfig);
  extern void (STDCALL *grSstOrigin)(GrOriginLocation_t origin);
  extern void (STDCALL *grSstSelect)(int which_sst);

  extern int (STDCALL *grSstScreenHeight)(void);
  extern int (STDCALL *grSstScreenWidth)(void);
  extern uint32_t (STDCALL *grSstStatus)(void);

/***  Drawing Statistics */
  extern void (STDCALL *grSstPerfStats)(GrSstPerfStats_t *pStats);
  extern void (STDCALL *grSstResetPerfStats)(void);
  extern void (STDCALL *grResetTriStats)();
  extern void (STDCALL *grTriStats)(uint32_t *trisProcessed, uint32_t *trisDrawn);

/*** Glide configuration and special effect maintenance functions */
  extern void (STDCALL *grAlphaBlendFunction)(GrAlphaBlendFnc_t rgb_sf, GrAlphaBlendFnc_t rgb_df, GrAlphaBlendFnc_t alpha_sf, GrAlphaBlendFnc_t alpha_df);
  extern void (STDCALL *grAlphaCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, FxBool invert);
  extern void (STDCALL *grAlphaControlsITRGBLighting)(FxBool enable);
  extern void (STDCALL *grAlphaTestFunction)(GrCmpFnc_t function);
  extern void (STDCALL *grAlphaTestReferenceValue)(GrAlpha_t value);
  extern void (STDCALL *grChromakeyMode)(GrChromakeyMode_t mode);
  extern void (STDCALL *grChromakeyValue)(GrColor_t value);
  extern void (STDCALL *grClipWindow)(int minx, int miny, int maxx, int maxy);
  extern void (STDCALL *grColorCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, FxBool invert);
  extern void (STDCALL *grColorMask)(FxBool rgb, FxBool a);
  extern void (STDCALL *grCullMode)(GrCullMode_t mode);
  extern void (STDCALL *grConstantColorValue)(GrColor_t value);
  extern void (STDCALL *grConstantColorValue4)(float a, float r, float g, float b);
  extern void (STDCALL *grDepthBiasLevel)(int16_t level);
  extern void (STDCALL *grDepthBufferFunction)(GrCmpFnc_t function);
  extern void (STDCALL *grDepthBufferMode)(GrDepthBufferMode_t mode);
  extern void (STDCALL *grDepthMask)(FxBool mask);
  extern void (STDCALL *grDisableAllEffects)(void);
  extern void (STDCALL *grDitherMode)(GrDitherMode_t mode);
  extern void (STDCALL *grFogColorValue)(GrColor_t fogcolor);
  extern void (STDCALL *grFogMode)(GrFogMode_t mode);
  extern void (STDCALL *grFogTable)(const GrFog_t ft[GR_FOG_TABLE_SIZE]);
  extern void (STDCALL *grGammaCorrectionValue)(float value);
  extern void (STDCALL *grSplash)(float x, float y, float width, float height, uint32_t frame);

/*** texture mapping control functions */
  extern uint32_t (STDCALL *grTexCalcMemRequired)(GrLOD_t lodmin, GrLOD_t lodmax, GrAspectRatio_t aspect, GrTextureFormat_t fmt);
  extern uint32_t (STDCALL *grTexTextureMemRequired)(uint32_t evenOdd, GrTexInfo *info);
  extern uint32_t (STDCALL *grTexMinAddress)(GrChipID_t tmu);
  extern uint32_t (STDCALL *grTexMaxAddress)(GrChipID_t tmu);
  extern void (STDCALL *grTexNCCTable)(GrChipID_t tmu, GrNCCTable_t table);
  extern void (STDCALL *grTexSource)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info);
  extern void (STDCALL *grTexClampMode)(GrChipID_t tmu, GrTextureClampMode_t s_clampmode, GrTextureClampMode_t t_clampmode);
  extern void (STDCALL *grTexCombine)(GrChipID_t tmu, GrCombineFunction_t rgb_function, GrCombineFactor_t rgb_factor, GrCombineFunction_t alpha_function, GrCombineFactor_t alpha_factor, FxBool rgb_invert, FxBool alpha_invert);
  extern void (STDCALL *grTexCombineFunction)(GrChipID_t tmu, GrTextureCombineFnc_t fnc);
  extern void (STDCALL *grTexDetailControl)(GrChipID_t tmu, int lod_bias, uint8_t detail_scale, float detail_max);
  extern void (STDCALL *grTexFilterMode)(GrChipID_t tmu, GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode);
  extern void (STDCALL *grTexLodBiasValue)(GrChipID_t tmu, float bias);
  extern void (STDCALL *grTexDownloadMipMap)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info);
  extern void (STDCALL *grTexDownloadMipMapLevel)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void *data);
  extern void (STDCALL *grTexDownloadMipMapLevelPartial)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void *data, int start, int end);
  extern void (STDCALL *ConvertAndDownloadRle)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, uint8_t *bm_data, long bm_h, uint32_t u0, uint32_t v0, uint32_t width, uint32_t height, uint32_t dest_width, uint32_t dest_height, uint16_t *tlut);
  extern void (STDCALL *grCheckForRoom)(int32_t n);
  extern void (STDCALL *grTexDownloadTable)(GrChipID_t tmu, GrTexTable_t type, void *data);
  extern void (STDCALL *grTexDownloadTablePartial)(GrChipID_t tmu, GrTexTable_t type, void *data, int start, int end);
  extern void (STDCALL *grTexMipMapMode)(GrChipID_t tmu, GrMipMapMode_t mode, FxBool lodBlend);
  extern void (STDCALL *grTexMultibase)(GrChipID_t tmu, FxBool enable);
  extern void (STDCALL *grTexMultibaseAddress)(GrChipID_t tmu, GrTexBaseRange_t range, uint32_t startAddress, uint32_t evenOdd, GrTexInfo *info);

/*** linear frame buffer functions */
  extern FxBool (STDCALL *grLfbLock)(GrLock_t type, GrBuffer_t buffer, GrLfbWriteMode_t writeMode, GrOriginLocation_t origin, FxBool pixelPipeline, GrLfbInfo_t *info);
  extern FxBool (STDCALL *grLfbUnlock)(GrLock_t type, GrBuffer_t buffer);
  extern void (STDCALL *grLfbConstantAlpha)(GrAlpha_t alpha);
  extern void (STDCALL *grLfbConstantDepth)(uint16_t depth);
  extern void (STDCALL *grLfbWriteColorSwizzle)(FxBool swizzleBytes, FxBool swapWords);
  extern void (STDCALL *grLfbWriteColorFormat)(GrColorFormat_t colorFormat);
  extern FxBool (STDCALL *grLfbWriteRegion)(GrBuffer_t dst_buffer, uint32_t dst_x, uint32_t dst_y, GrLfbSrcFmt_t src_format, uint32_t src_width, uint32_t src_height, int32_t src_stride, void *src_data);
  extern FxBool (STDCALL *grLfbReadRegion)(GrBuffer_t src_buffer, uint32_t src_x, uint32_t src_y, uint32_t src_width, uint32_t src_height, uint32_t dst_stride, void *dst_data);

/***  Antialiasing Functions */
  extern void (STDCALL *grAADrawLine)(const GrVertex *v1, const GrVertex *v2);
  extern void (STDCALL *grAADrawPoint)(const GrVertex *pt);
  extern void (STDCALL *grAADrawPolygon)(const int nverts, const int ilist[], const GrVertex vlist[]);
  extern void (STDCALL *grAADrawPolygonVertexList)(const int nverts, const GrVertex vlist[]);
  extern void (STDCALL *grAADrawTriangle)(const GrVertex *a, const GrVertex *b, const GrVertex *c, FxBool ab_antialias, FxBool bc_antialias, FxBool ca_antialias);

/*** glide management functions */
  extern void (STDCALL *grGlideInit)(void);
  extern void (STDCALL *grGlideShutdown)(void);
  extern void (STDCALL *grGlideGetVersion)(char version[80]);
  extern void (STDCALL *grGlideGetState)(GrState *state);
  extern void (STDCALL *grGlideSetState)(const GrState *state);
  extern void (STDCALL *grGlideShamelessPlug)(const FxBool on);
  extern void (STDCALL *grHints)(GrHint_t hintType, uint32_t hintMask);

/* Glide Utility routines */

/*** utility texture functions */
  extern GrMipMapId_t (STDCALL *guTexAllocateMemory)(GrChipID_t tmu, uint8_t odd_even_mask, int width, int height, GrTextureFormat_t fmt, GrMipMapMode_t mm_mode, GrLOD_t smallest_lod, GrLOD_t largest_lod, GrAspectRatio_t aspect, GrTextureClampMode_t s_clamp_mode, GrTextureClampMode_t t_clamp_mode, GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode, float lod_bias, FxBool trilinear);
  extern FxBool (STDCALL *guTexChangeAttributes)(GrMipMapId_t mmid, int width, int height, GrTextureFormat_t fmt, GrMipMapMode_t mm_mode, GrLOD_t smallest_lod, GrLOD_t largest_lod, GrAspectRatio_t aspect, GrTextureClampMode_t s_clamp_mode, GrTextureClampMode_t t_clamp_mode, GrTextureFilterMode_t minFilterMode, GrTextureFilterMode_t magFilterMode);
  extern void (STDCALL *guTexCombineFunction)(GrChipID_t tmu, GrTextureCombineFnc_t fnc);
  extern GrMipMapId_t (STDCALL *guTexGetCurrentMipMap)(GrChipID_t tmu);
  extern GrMipMapInfo* (STDCALL *guTexGetMipMapInfo)(GrMipMapId_t mmid);
  extern uint32_t (STDCALL *guTexMemQueryAvail)(GrChipID_t tmu);
  extern void (STDCALL *guTexMemReset)(void);
  extern void (STDCALL *guTexDownloadMipMap)(GrMipMapId_t mmid, const void *src, const GuNccTable *table);
  extern void (STDCALL *guTexDownloadMipMapLevel)(GrMipMapId_t mmid, GrLOD_t lod, const void **src);
  extern void (STDCALL *guTexSource)(GrMipMapId_t id);

/*** rendering functions */
  extern void (STDCALL *guAADrawTriangleWithClip)(const GrVertex *a, const GrVertex *b, const GrVertex *c);
  extern void (STDCALL *guDrawTriangleWithClip)(const GrVertex *a, const GrVertex *b, const GrVertex *c);
  extern void (STDCALL *guDrawPolygonVertexListWithClip)(int nverts, const GrVertex vlist[]);

/*** hi-level rendering utility functions */
  extern void (STDCALL *guAlphaSource)(GrAlphaSource_t mode);
  extern void (STDCALL *guColorCombineFunction)(GrColorCombineFnc_t fnc);
  extern void (STDCALL *guFbReadRegion)(const int src_x, const int src_y, const int w, const int h, const void *dst, const int strideInBytes);
  extern int (STDCALL *guEncodeRLE16)(void *dst, void *src, uint32_t width, uint32_t height);
  extern uint16_t * (STDCALL *guTexCreateColorMipMap)(void);

/*** movie capture stuff */
  extern void (STDCALL *guMovieStart)(void);
  extern void (STDCALL *guMovieStop)(void);
  extern void (STDCALL *guMovieSetName)(const char *name);

/*** fog stuff */
  extern float (STDCALL *guFogTableIndexToW)(int i);
  extern void (STDCALL *guFogGenerateExp)(GrFog_t fogtable[GR_FOG_TABLE_SIZE], float density);
  extern void (STDCALL *guFogGenerateExp2)(GrFog_t fogtable[GR_FOG_TABLE_SIZE], float density);
  extern void (STDCALL *guFogGenerateLinear)(GrFog_t fogtable[GR_FOG_TABLE_SIZE], float nearZ, float farZ);

/*** endian stuff */
  extern uint32_t (STDCALL *guEndianSwapWords)(uint32_t value);
  extern uint16_t (STDCALL *guEndianSwapBytes)(uint16_t value);

/*** hi-level texture manipulation tools. */
  extern FxBool (STDCALL *gu3dfGetInfo)(const char *filename, Gu3dfInfo *info);
  extern FxBool (STDCALL *gu3dfLoad)(const char *filename, Gu3dfInfo *data);

}
#endif
