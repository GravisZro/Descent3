#ifndef LOAD_LIB_GLIDE
#define LOAD_LIB_GLIDE

// System
#include <stdint.h>

// System copied to Project
#include "glide3x/glide.h"
#include "glide3x/glideutl.h"

// Project
#include "module.h"

using bool32_t = int32_t;

namespace glide
{
  bool load(void);
  bool unload(void);

/* rendering functions */
  extern void  (STDCALL *grDrawPoint)(const void* pt);
  extern void  (STDCALL *grDrawLine)(const void* v1, const void* v2);
  extern void  (STDCALL *grDrawTriangle)(const void* a, const void* b, const void* c);
  extern void  (STDCALL *grVertexLayout)(uint32_t param, int32_t offset, uint32_t mode);
  extern void  (STDCALL *grDrawVertexArray)(uint32_t mode, uint32_t Count, void* pointers);
  extern void  (STDCALL *grDrawVertexArrayContiguous)(uint32_t mode, uint32_t Count, void* pointers, uint32_t stride);

/* Antialiasing Functions */
  extern void  (STDCALL *grAADrawTriangle)(const void* a, const void* b, const void* c, bool32_t ab_antialias, bool32_t bc_antialias, bool32_t ca_antialias);

/* buffer management */
  extern void  (STDCALL *grBufferClear)(GrColor_t color, GrAlpha_t alpha, uint32_t depth);
  extern void  (STDCALL *grBufferSwap)(int swap_interval);
  extern void  (STDCALL *grRenderBuffer)(GrBuffer_t buffer);

/* error management */
  extern void  (STDCALL *grErrorSetCallback)(void (*callback)(const char* string, bool32_t fatal));

/* SST routines */
  extern void  (STDCALL *grFinish)(void);
  extern void  (STDCALL *grFlush)(void);
  extern GrContext_t  (STDCALL *grSstWinOpen)(uint32_t hWnd, GrScreenResolution_t screen_resolution, GrScreenRefresh_t refresh_rate, GrColorFormat_t color_format, GrOriginLocation_t origin_location, int nColBuffers, int nAuxBuffers);
  extern bool32_t  (STDCALL *grSstWinClose)(GrContext_t context);
  extern bool32_t  (STDCALL *grSelectContext)(GrContext_t context);
  extern void  (STDCALL *grSstOrigin)(GrOriginLocation_t origin);
  extern void  (STDCALL *grSstSelect)(int which_sst);

/* Glide configuration and special effect maintenance functions */
  extern void  (STDCALL *grAlphaBlendFunction)(GrAlphaBlendFnc_t rgb_sf, GrAlphaBlendFnc_t rgb_df, GrAlphaBlendFnc_t alpha_sf, GrAlphaBlendFnc_t alpha_df);
  extern void  (STDCALL *grAlphaCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, bool32_t invert);
  extern void  (STDCALL *grAlphaControlsITRGBLighting)(bool32_t enable);
  extern void  (STDCALL *grAlphaTestFunction)(GrCmpFnc_t function);
  extern void  (STDCALL *grAlphaTestReferenceValue)(GrAlpha_t value);
  extern void  (STDCALL *grChromakeyMode)(GrChromakeyMode_t mode);
  extern void  (STDCALL *grChromakeyValue)(GrColor_t value);
  extern void  (STDCALL *grClipWindow)(uint32_t minx, uint32_t miny, uint32_t maxx, uint32_t maxy);
  extern void  (STDCALL *grColorCombine)(GrCombineFunction_t function, GrCombineFactor_t factor, GrCombineLocal_t local, GrCombineOther_t other, bool32_t invert);
  extern void  (STDCALL *grColorMask)(bool32_t rgb, bool32_t a);
  extern void  (STDCALL *grCullMode)(GrCullMode_t mode);
  extern void  (STDCALL *grConstantColorValue)(GrColor_t value);
  extern void  (STDCALL *grDepthBiasLevel)(uint32_t level);
  extern void  (STDCALL *grDepthBufferFunction)(GrCmpFnc_t function);
  extern void  (STDCALL *grDepthBufferMode)(GrDepthBufferMode_t mode);
  extern void  (STDCALL *grDepthMask)(bool32_t mask);
  extern void  (STDCALL *grDisableAllEffects)(void);
  extern void  (STDCALL *grDitherMode)(GrDitherMode_t mode);
  extern void  (STDCALL *grFogColorValue)(GrColor_t fogcolor);
  extern void  (STDCALL *grFogMode)(GrFogMode_t mode);
  extern void  (STDCALL *grFogTable)(const GrFog_t ft[]);
  extern void  (STDCALL *grLoadGammaTable)(uint32_t nentries, uint32_t* red, uint32_t* green, uint32_t* blue);
  extern void  (STDCALL *grSplash)(float x, float y, float width, float height, uint32_t frame);
  extern bool32_t  (STDCALL *grGet)(uint32_t pname, uint32_t plength, int32_t* params);
  extern const char*  (STDCALL *grGetString)(uint32_t pname);
  extern int32_t  (STDCALL *grQueryResolutions)(const GrResolution* resTemplate, GrResolution* output);
  extern bool32_t  (STDCALL *grReset)(uint32_t what);
  extern GrProc  (STDCALL *grGetProcAddress)(char* procName);
  extern void  (STDCALL *grEnable)(GrEnableMode_t mode);
  extern void  (STDCALL *grDisable)(GrEnableMode_t mode);
  extern void  (STDCALL *grCoordinateSpace)(GrCoordinateSpaceMode_t mode);
  extern void  (STDCALL *grDepthRange)(float n, float f);
  extern void  (STDCALL *grViewport)(int32_t x, int32_t y, int32_t width, int32_t height);

/* texture mapping control functions */
  extern uint32_t  (STDCALL *grTexCalcMemRequired)(GrLOD_t lodmin, GrLOD_t lodmax, GrAspectRatio_t aspect, GrTextureFormat_t fmt);
  extern uint32_t  (STDCALL *grTexTextureMemRequired)(uint32_t evenOdd, GrTexInfo* info);
  extern uint32_t  (STDCALL *grTexMinAddress)(GrChipID_t tmu);
  extern uint32_t  (STDCALL *grTexMaxAddress)(GrChipID_t tmu);
  extern void  (STDCALL *grTexNCCTable)(GrNCCTable_t table);
  extern void  (STDCALL *grTexSource)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo* info);
  extern void  (STDCALL *grTexClampMode)(GrChipID_t tmu, GrTextureClampMode_t s_clampmode, GrTextureClampMode_t t_clampmode);
  extern void  (STDCALL *grTexCombine)(GrChipID_t tmu, GrCombineFunction_t rgb_function, GrCombineFactor_t rgb_factor, GrCombineFunction_t alpha_function, GrCombineFactor_t alpha_factor, bool32_t rgb_invert, bool32_t alpha_invert);
  extern void  (STDCALL *grTexDetailControl)(GrChipID_t tmu, int lod_bias, uint8_t detail_scale, float detail_max);
  extern void  (STDCALL *grTexFilterMode)(GrChipID_t tmu, GrTextureFilterMode_t minfilter_mode, GrTextureFilterMode_t magfilter_mode);
  extern void  (STDCALL *grTexLodBiasValue)(GrChipID_t tmu, float bias);
  extern void  (STDCALL *grTexDownloadMipMap)(GrChipID_t tmu, uint32_t startAddress, uint32_t evenOdd, GrTexInfo* info);
  extern void  (STDCALL *grTexDownloadMipMapLevel)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void* data);
  extern bool32_t  (STDCALL *grTexDownloadMipMapLevelPartial)(GrChipID_t tmu, uint32_t startAddress, GrLOD_t thisLod, GrLOD_t largeLod, GrAspectRatio_t aspectRatio, GrTextureFormat_t format, uint32_t evenOdd, void* data, int start, int end);
  extern void  (STDCALL *grTexDownloadTable)(GrTexTable_t type, void* data);
  extern void  (STDCALL *grTexDownloadTablePartial)(GrTexTable_t type, void* data, int start, int end);
  extern void  (STDCALL *grTexMipMapMode)(GrChipID_t tmu, GrMipMapMode_t mode, bool32_t lodBlend);
  extern void  (STDCALL *grTexMultibase)(GrChipID_t tmu, bool32_t enable);
  extern void  (STDCALL *grTexMultibaseAddress)(GrChipID_t tmu, GrTexBaseRange_t range, uint32_t startAddress, uint32_t evenOdd, GrTexInfo* info);

/* linear frame buffer functions */
  extern bool32_t  (STDCALL *grLfbLock)(GrLock_t type, GrBuffer_t buffer, GrLfbWriteMode_t writeMode, GrOriginLocation_t origin, bool32_t pixelPipeline, GrLfbInfo_t* info);
  extern bool32_t  (STDCALL *grLfbUnlock)(GrLock_t type, GrBuffer_t buffer);
  extern void  (STDCALL *grLfbConstantAlpha)(GrAlpha_t alpha);
  extern void  (STDCALL *grLfbConstantDepth)(uint32_t depth);
  extern void  (STDCALL *grLfbWriteColorSwizzle)(bool32_t swizzleBytes, bool32_t swapWords);
  extern void  (STDCALL *grLfbWriteColorFormat)(GrColorFormat_t colorFormat);
  extern bool32_t  (STDCALL *grLfbWriteRegion)(GrBuffer_t dst_buffer, uint32_t dst_x, uint32_t dst_y, GrLfbSrcFmt_t src_format, uint32_t src_width, uint32_t src_height, bool32_t pixelPipeline, int32_t src_stride, void* src_data);
  extern bool32_t  (STDCALL *grLfbReadRegion)(GrBuffer_t src_buffer, uint32_t src_x, uint32_t src_y, uint32_t src_width, uint32_t src_height, uint32_t dst_stride, void* dst_data);

/* glide management functions */
  extern void  (STDCALL *grGlideInit)(void);
  extern void  (STDCALL *grGlideShutdown)(void);
  extern void  (STDCALL *grGlideGetState)(void* state);
  extern void  (STDCALL *grGlideSetState)(const void* state);
  extern void  (STDCALL *grGlideGetVertexLayout)(void* layout);
  extern void  (STDCALL *grGlideSetVertexLayout)(const void* layout);

/* Gamma functions */
  extern void  (STDCALL *guGammaCorrectionRGB)(float red, float green, float blue);

/* fog stuff */
  extern float  (STDCALL *guFogTableIndexToW)(int i);
  extern void  (STDCALL *guFogGenerateExp)(GrFog_t* fogtable, float density);
  extern void  (STDCALL *guFogGenerateExp2)(GrFog_t* fogtable, float density);
  extern void  (STDCALL *guFogGenerateLinear)(GrFog_t* fogtable, float nearZ, float farZ);

/* hi-level texture manipulation tools. */
  extern bool32_t  (STDCALL *gu3dfGetInfo)(const char* filename, Gu3dfInfo* info);
  extern bool32_t  (STDCALL *gu3dfLoad)(const char* filename, Gu3dfInfo* data);
}
#endif
