---
search: false
---

# renderextensionsgl.h File Reference

**[Go to the documentation of this file.](renderextensionsgl_8h.md)**
Source: `include/ffw/graphics/renderextensionsgl.h`

    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
```cpp
/* This file is part of FineFramework project */
#ifndef FFW_GL_EXTENSIONS
#define FFW_GL_EXTENSIONS
#include "../config.h"

#ifdef FFW_WINDOWS
#ifndef WINGDIAPI
#define FFW_WINGDIAPI_DEFINED 1
#define WINGDIAPI __declspec(dllimport)
#define APIENTRY _stdcall
#endif
#include <GL/gl.h>
#define GL_VERSION_1_0 1
#define GL_VERSION_1_1 1
#include "GL/glcorearb.h"
#endif

#ifdef FFW_LINUX
#include <GL/gl.h>
#define GL_VERSION_1_0 1
#define GL_VERSION_1_1 1
#include "GL/glcorearb.h"
#endif

#ifdef FFW_OSX
#define GL_DO_NOT_WARN_IF_MULTI_GL_VERSION_HEADERS_INCLUDED
#include <OpenGL/gl3.h>
#include <OpenGL/gl.h>
#define GL_VERSION_1_0 1
#define GL_VERSION_1_1 1
#include "GL/glcorearb.h"
#endif

namespace ffw {
    namespace gl {

#ifdef GL_VERSION_1_2
        extern FFW_API PFNGLCOPYTEXSUBIMAGE3DPROC glCopyTexSubImage3D;
        extern FFW_API PFNGLDRAWRANGEELEMENTSPROC glDrawRangeElements;
        extern FFW_API PFNGLTEXIMAGE3DPROC glTexImage3D;
        extern FFW_API PFNGLTEXSUBIMAGE3DPROC glTexSubImage3D;
#endif /* GL_VERSION_1_2 */

#ifdef GL_VERSION_1_3
        extern FFW_API PFNGLACTIVETEXTUREPROC glActiveTexture;
        extern FFW_API PFNGLCOMPRESSEDTEXIMAGE1DPROC glCompressedTexImage1D;
        extern FFW_API PFNGLCOMPRESSEDTEXIMAGE2DPROC glCompressedTexImage2D;
        extern FFW_API PFNGLCOMPRESSEDTEXIMAGE3DPROC glCompressedTexImage3D;
        extern FFW_API PFNGLCOMPRESSEDTEXSUBIMAGE1DPROC glCompressedTexSubImage1D;
        extern FFW_API PFNGLCOMPRESSEDTEXSUBIMAGE2DPROC glCompressedTexSubImage2D;
        extern FFW_API PFNGLCOMPRESSEDTEXSUBIMAGE3DPROC glCompressedTexSubImage3D;
        extern FFW_API PFNGLGETCOMPRESSEDTEXIMAGEPROC glGetCompressedTexImage;
        extern FFW_API PFNGLSAMPLECOVERAGEPROC glSampleCoverage;
#endif /* GL_VERSION_1_3 */

#ifdef GL_VERSION_1_4
        extern FFW_API PFNGLBLENDCOLORPROC glBlendColor;
        extern FFW_API PFNGLBLENDEQUATIONPROC glBlendEquation;
        extern FFW_API PFNGLBLENDFUNCSEPARATEPROC glBlendFuncSeparate;
        extern FFW_API PFNGLMULTIDRAWARRAYSPROC glMultiDrawArrays;
        extern FFW_API PFNGLMULTIDRAWELEMENTSPROC glMultiDrawElements;
        extern FFW_API PFNGLPOINTPARAMETERFPROC glPointParameterf;
        extern FFW_API PFNGLPOINTPARAMETERFVPROC glPointParameterfv;
        extern FFW_API PFNGLPOINTPARAMETERIPROC glPointParameteri;
        extern FFW_API PFNGLPOINTPARAMETERIVPROC glPointParameteriv;
#endif /* GL_VERSION_1_4 */

#ifdef GL_VERSION_1_5
        extern FFW_API PFNGLBEGINQUERYPROC glBeginQuery;
        extern FFW_API PFNGLBINDBUFFERPROC glBindBuffer;
        extern FFW_API PFNGLBUFFERDATAPROC glBufferData;
        extern FFW_API PFNGLBUFFERSUBDATAPROC glBufferSubData;
        extern FFW_API PFNGLDELETEBUFFERSPROC glDeleteBuffers;
        extern FFW_API PFNGLDELETEQUERIESPROC glDeleteQueries;
        extern FFW_API PFNGLENDQUERYPROC glEndQuery;
        extern FFW_API PFNGLGENBUFFERSPROC glGenBuffers;
        extern FFW_API PFNGLGENQUERIESPROC glGenQueries;
        extern FFW_API PFNGLGETBUFFERPARAMETERIVPROC glGetBufferParameteriv;
        extern FFW_API PFNGLGETBUFFERPOINTERVPROC glGetBufferPointerv;
        extern FFW_API PFNGLGETBUFFERSUBDATAPROC glGetBufferSubData;
        extern FFW_API PFNGLGETQUERYIVPROC glGetQueryiv;
        extern FFW_API PFNGLGETQUERYOBJECTIVPROC glGetQueryObjectiv;
        extern FFW_API PFNGLGETQUERYOBJECTUIVPROC glGetQueryObjectuiv;
        extern FFW_API PFNGLISBUFFERPROC glIsBuffer;
        extern FFW_API PFNGLISQUERYPROC glIsQuery;
        extern FFW_API PFNGLMAPBUFFERPROC glMapBuffer;
        extern FFW_API PFNGLUNMAPBUFFERPROC glUnmapBuffer;
#endif /* GL_VERSION_1_5 */

#ifdef GL_VERSION_2_0
        extern FFW_API PFNGLATTACHSHADERPROC glAttachShader;
        extern FFW_API PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
        extern FFW_API PFNGLBLENDEQUATIONSEPARATEPROC glBlendEquationSeparate;
        extern FFW_API PFNGLCOMPILESHADERPROC glCompileShader;
        extern FFW_API PFNGLCREATEPROGRAMPROC glCreateProgram;
        extern FFW_API PFNGLCREATESHADERPROC glCreateShader;
        extern FFW_API PFNGLDELETEPROGRAMPROC glDeleteProgram;
        extern FFW_API PFNGLDELETESHADERPROC glDeleteShader;
        extern FFW_API PFNGLDETACHSHADERPROC glDetachShader;
        extern FFW_API PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
        extern FFW_API PFNGLDRAWBUFFERSPROC glDrawBuffers;
        extern FFW_API PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
        extern FFW_API PFNGLGETACTIVEATTRIBPROC glGetActiveAttrib;
        extern FFW_API PFNGLGETACTIVEUNIFORMPROC glGetActiveUniform;
        extern FFW_API PFNGLGETATTACHEDSHADERSPROC glGetAttachedShaders;
        extern FFW_API PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
        extern FFW_API PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
        extern FFW_API PFNGLGETPROGRAMIVPROC glGetProgramiv;
        extern FFW_API PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
        extern FFW_API PFNGLGETSHADERIVPROC glGetShaderiv;
        extern FFW_API PFNGLGETSHADERSOURCEPROC glGetShaderSource;
        extern FFW_API PFNGLGETUNIFORMFVPROC glGetUniformfv;
        extern FFW_API PFNGLGETUNIFORMIVPROC glGetUniformiv;
        extern FFW_API PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
        extern FFW_API PFNGLGETVERTEXATTRIBDVPROC glGetVertexAttribdv;
        extern FFW_API PFNGLGETVERTEXATTRIBFVPROC glGetVertexAttribfv;
        extern FFW_API PFNGLGETVERTEXATTRIBIVPROC glGetVertexAttribiv;
        extern FFW_API PFNGLGETVERTEXATTRIBPOINTERVPROC glGetVertexAttribPointerv;
        extern FFW_API PFNGLISPROGRAMPROC glIsProgram;
        extern FFW_API PFNGLISSHADERPROC glIsShader;
        extern FFW_API PFNGLLINKPROGRAMPROC glLinkProgram;
        extern FFW_API PFNGLSHADERSOURCEPROC glShaderSource;
        extern FFW_API PFNGLSTENCILFUNCSEPARATEPROC glStencilFuncSeparate;
        extern FFW_API PFNGLSTENCILMASKSEPARATEPROC glStencilMaskSeparate;
        extern FFW_API PFNGLSTENCILOPSEPARATEPROC glStencilOpSeparate;
        extern FFW_API PFNGLUNIFORM1FPROC glUniform1f;
        extern FFW_API PFNGLUNIFORM1FVPROC glUniform1fv;
        extern FFW_API PFNGLUNIFORM1IPROC glUniform1i;
        extern FFW_API PFNGLUNIFORM1IVPROC glUniform1iv;
        extern FFW_API PFNGLUNIFORM2FPROC glUniform2f;
        extern FFW_API PFNGLUNIFORM2FVPROC glUniform2fv;
        extern FFW_API PFNGLUNIFORM2IPROC glUniform2i;
        extern FFW_API PFNGLUNIFORM2IVPROC glUniform2iv;
        extern FFW_API PFNGLUNIFORM3FPROC glUniform3f;
        extern FFW_API PFNGLUNIFORM3FVPROC glUniform3fv;
        extern FFW_API PFNGLUNIFORM3IPROC glUniform3i;
        extern FFW_API PFNGLUNIFORM3IVPROC glUniform3iv;
        extern FFW_API PFNGLUNIFORM4FPROC glUniform4f;
        extern FFW_API PFNGLUNIFORM4FVPROC glUniform4fv;
        extern FFW_API PFNGLUNIFORM4IPROC glUniform4i;
        extern FFW_API PFNGLUNIFORM4IVPROC glUniform4iv;
        extern FFW_API PFNGLUNIFORMMATRIX2FVPROC glUniformMatrix2fv;
        extern FFW_API PFNGLUNIFORMMATRIX3FVPROC glUniformMatrix3fv;
        extern FFW_API PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
        extern FFW_API PFNGLUSEPROGRAMPROC glUseProgram;
        extern FFW_API PFNGLVALIDATEPROGRAMPROC glValidateProgram;
        extern FFW_API PFNGLVERTEXATTRIB1DPROC glVertexAttrib1d;
        extern FFW_API PFNGLVERTEXATTRIB1DVPROC glVertexAttrib1dv;
        extern FFW_API PFNGLVERTEXATTRIB1FPROC glVertexAttrib1f;
        extern FFW_API PFNGLVERTEXATTRIB1FVPROC glVertexAttrib1fv;
        extern FFW_API PFNGLVERTEXATTRIB1SPROC glVertexAttrib1s;
        extern FFW_API PFNGLVERTEXATTRIB1SVPROC glVertexAttrib1sv;
        extern FFW_API PFNGLVERTEXATTRIB2DPROC glVertexAttrib2d;
        extern FFW_API PFNGLVERTEXATTRIB2DVPROC glVertexAttrib2dv;
        extern FFW_API PFNGLVERTEXATTRIB2FPROC glVertexAttrib2f;
        extern FFW_API PFNGLVERTEXATTRIB2FVPROC glVertexAttrib2fv;
        extern FFW_API PFNGLVERTEXATTRIB2SPROC glVertexAttrib2s;
        extern FFW_API PFNGLVERTEXATTRIB2SVPROC glVertexAttrib2sv;
        extern FFW_API PFNGLVERTEXATTRIB3DPROC glVertexAttrib3d;
        extern FFW_API PFNGLVERTEXATTRIB3DVPROC glVertexAttrib3dv;
        extern FFW_API PFNGLVERTEXATTRIB3FPROC glVertexAttrib3f;
        extern FFW_API PFNGLVERTEXATTRIB3FVPROC glVertexAttrib3fv;
        extern FFW_API PFNGLVERTEXATTRIB3SPROC glVertexAttrib3s;
        extern FFW_API PFNGLVERTEXATTRIB3SVPROC glVertexAttrib3sv;
        extern FFW_API PFNGLVERTEXATTRIB4BVPROC glVertexAttrib4bv;
        extern FFW_API PFNGLVERTEXATTRIB4DPROC glVertexAttrib4d;
        extern FFW_API PFNGLVERTEXATTRIB4DVPROC glVertexAttrib4dv;
        extern FFW_API PFNGLVERTEXATTRIB4FPROC glVertexAttrib4f;
        extern FFW_API PFNGLVERTEXATTRIB4FVPROC glVertexAttrib4fv;
        extern FFW_API PFNGLVERTEXATTRIB4IVPROC glVertexAttrib4iv;
        extern FFW_API PFNGLVERTEXATTRIB4NBVPROC glVertexAttrib4Nbv;
        extern FFW_API PFNGLVERTEXATTRIB4NIVPROC glVertexAttrib4Niv;
        extern FFW_API PFNGLVERTEXATTRIB4NSVPROC glVertexAttrib4Nsv;
        extern FFW_API PFNGLVERTEXATTRIB4NUBPROC glVertexAttrib4Nub;
        extern FFW_API PFNGLVERTEXATTRIB4NUBVPROC glVertexAttrib4Nubv;
        extern FFW_API PFNGLVERTEXATTRIB4NUIVPROC glVertexAttrib4Nuiv;
        extern FFW_API PFNGLVERTEXATTRIB4NUSVPROC glVertexAttrib4Nusv;
        extern FFW_API PFNGLVERTEXATTRIB4SPROC glVertexAttrib4s;
        extern FFW_API PFNGLVERTEXATTRIB4SVPROC glVertexAttrib4sv;
        extern FFW_API PFNGLVERTEXATTRIB4UBVPROC glVertexAttrib4ubv;
        extern FFW_API PFNGLVERTEXATTRIB4UIVPROC glVertexAttrib4uiv;
        extern FFW_API PFNGLVERTEXATTRIB4USVPROC glVertexAttrib4usv;
        extern FFW_API PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
#endif /* GL_VERSION_2_0 */

#ifdef GL_VERSION_2_1
        extern FFW_API PFNGLUNIFORMMATRIX2X3FVPROC glUniformMatrix2x3fv;
        extern FFW_API PFNGLUNIFORMMATRIX2X4FVPROC glUniformMatrix2x4fv;
        extern FFW_API PFNGLUNIFORMMATRIX3X2FVPROC glUniformMatrix3x2fv;
        extern FFW_API PFNGLUNIFORMMATRIX3X4FVPROC glUniformMatrix3x4fv;
        extern FFW_API PFNGLUNIFORMMATRIX4X2FVPROC glUniformMatrix4x2fv;
        extern FFW_API PFNGLUNIFORMMATRIX4X3FVPROC glUniformMatrix4x3fv;
#endif /* GL_VERSION_2_1 */

#ifdef GL_VERSION_3_0
        extern FFW_API PFNGLBEGINCONDITIONALRENDERPROC glBeginConditionalRender;
        extern FFW_API PFNGLBEGINTRANSFORMFEEDBACKPROC glBeginTransformFeedback;
        extern FFW_API PFNGLBINDBUFFERBASEPROC glBindBufferBase;
        extern FFW_API PFNGLBINDBUFFERRANGEPROC glBindBufferRange;
        extern FFW_API PFNGLBINDFRAGDATALOCATIONPROC glBindFragDataLocation;
        extern FFW_API PFNGLBINDFRAMEBUFFERPROC glBindFramebuffer;
        extern FFW_API PFNGLBINDRENDERBUFFERPROC glBindRenderbuffer;
        extern FFW_API PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
        extern FFW_API PFNGLBLITFRAMEBUFFERPROC glBlitFramebuffer;
        extern FFW_API PFNGLCHECKFRAMEBUFFERSTATUSPROC glCheckFramebufferStatus;
        extern FFW_API PFNGLCLAMPCOLORPROC glClampColor;
        extern FFW_API PFNGLCLEARBUFFERFIPROC glClearBufferfi;
        extern FFW_API PFNGLCLEARBUFFERFVPROC glClearBufferfv;
        extern FFW_API PFNGLCLEARBUFFERIVPROC glClearBufferiv;
        extern FFW_API PFNGLCLEARBUFFERUIVPROC glClearBufferuiv;
        extern FFW_API PFNGLCOLORMASKIPROC glColorMaski;
        extern FFW_API PFNGLDELETEFRAMEBUFFERSPROC glDeleteFramebuffers;
        extern FFW_API PFNGLDELETERENDERBUFFERSPROC glDeleteRenderbuffers;
        extern FFW_API PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
        extern FFW_API PFNGLDISABLEIPROC glDisablei;
        extern FFW_API PFNGLENABLEIPROC glEnablei;
        extern FFW_API PFNGLENDCONDITIONALRENDERPROC glEndConditionalRender;
        extern FFW_API PFNGLENDTRANSFORMFEEDBACKPROC glEndTransformFeedback;
        extern FFW_API PFNGLFLUSHMAPPEDBUFFERRANGEPROC glFlushMappedBufferRange;
        extern FFW_API PFNGLFRAMEBUFFERRENDERBUFFERPROC glFramebufferRenderbuffer;
        extern FFW_API PFNGLFRAMEBUFFERTEXTURE1DPROC glFramebufferTexture1D;
        extern FFW_API PFNGLFRAMEBUFFERTEXTURE2DPROC glFramebufferTexture2D;
        extern FFW_API PFNGLFRAMEBUFFERTEXTURE3DPROC glFramebufferTexture3D;
        extern FFW_API PFNGLFRAMEBUFFERTEXTURELAYERPROC glFramebufferTextureLayer;
        extern FFW_API PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
        extern FFW_API PFNGLGENFRAMEBUFFERSPROC glGenFramebuffers;
        extern FFW_API PFNGLGENRENDERBUFFERSPROC glGenRenderbuffers;
        extern FFW_API PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
        extern FFW_API PFNGLGETBOOLEANI_VPROC glGetBooleani_v;
        extern FFW_API PFNGLGETFRAGDATALOCATIONPROC glGetFragDataLocation;
        extern FFW_API PFNGLGETFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetFramebufferAttachmentParameteriv;
        extern FFW_API PFNGLGETINTEGERI_VPROC glGetIntegeri_v;
        extern FFW_API PFNGLGETRENDERBUFFERPARAMETERIVPROC glGetRenderbufferParameteriv;
        extern FFW_API PFNGLGETSTRINGIPROC glGetStringi;
        extern FFW_API PFNGLGETTEXPARAMETERIIVPROC glGetTexParameterIiv;
        extern FFW_API PFNGLGETTEXPARAMETERIUIVPROC glGetTexParameterIuiv;
        extern FFW_API PFNGLGETTRANSFORMFEEDBACKVARYINGPROC glGetTransformFeedbackVarying;
        extern FFW_API PFNGLGETUNIFORMUIVPROC glGetUniformuiv;
        extern FFW_API PFNGLGETVERTEXATTRIBIIVPROC glGetVertexAttribIiv;
        extern FFW_API PFNGLGETVERTEXATTRIBIUIVPROC glGetVertexAttribIuiv;
        extern FFW_API PFNGLISENABLEDIPROC glIsEnabledi;
        extern FFW_API PFNGLISFRAMEBUFFERPROC glIsFramebuffer;
        extern FFW_API PFNGLISRENDERBUFFERPROC glIsRenderbuffer;
        extern FFW_API PFNGLISVERTEXARRAYPROC glIsVertexArray;
        extern FFW_API PFNGLMAPBUFFERRANGEPROC glMapBufferRange;
        extern FFW_API PFNGLRENDERBUFFERSTORAGEMULTISAMPLEPROC glRenderbufferStorageMultisample;
        extern FFW_API PFNGLRENDERBUFFERSTORAGEPROC glRenderbufferStorage;
        extern FFW_API PFNGLTEXPARAMETERIIVPROC glTexParameterIiv;
        extern FFW_API PFNGLTEXPARAMETERIUIVPROC glTexParameterIuiv;
        extern FFW_API PFNGLTRANSFORMFEEDBACKVARYINGSPROC glTransformFeedbackVaryings;
        extern FFW_API PFNGLUNIFORM1UIPROC glUniform1ui;
        extern FFW_API PFNGLUNIFORM1UIVPROC glUniform1uiv;
        extern FFW_API PFNGLUNIFORM2UIPROC glUniform2ui;
        extern FFW_API PFNGLUNIFORM2UIVPROC glUniform2uiv;
        extern FFW_API PFNGLUNIFORM3UIPROC glUniform3ui;
        extern FFW_API PFNGLUNIFORM3UIVPROC glUniform3uiv;
        extern FFW_API PFNGLUNIFORM4UIPROC glUniform4ui;
        extern FFW_API PFNGLUNIFORM4UIVPROC glUniform4uiv;
        extern FFW_API PFNGLVERTEXATTRIBI1IPROC glVertexAttribI1i;
        extern FFW_API PFNGLVERTEXATTRIBI1IVPROC glVertexAttribI1iv;
        extern FFW_API PFNGLVERTEXATTRIBI1UIPROC glVertexAttribI1ui;
        extern FFW_API PFNGLVERTEXATTRIBI1UIVPROC glVertexAttribI1uiv;
        extern FFW_API PFNGLVERTEXATTRIBI2IPROC glVertexAttribI2i;
        extern FFW_API PFNGLVERTEXATTRIBI2IVPROC glVertexAttribI2iv;
        extern FFW_API PFNGLVERTEXATTRIBI2UIPROC glVertexAttribI2ui;
        extern FFW_API PFNGLVERTEXATTRIBI2UIVPROC glVertexAttribI2uiv;
        extern FFW_API PFNGLVERTEXATTRIBI3IPROC glVertexAttribI3i;
        extern FFW_API PFNGLVERTEXATTRIBI3IVPROC glVertexAttribI3iv;
        extern FFW_API PFNGLVERTEXATTRIBI3UIPROC glVertexAttribI3ui;
        extern FFW_API PFNGLVERTEXATTRIBI3UIVPROC glVertexAttribI3uiv;
        extern FFW_API PFNGLVERTEXATTRIBI4BVPROC glVertexAttribI4bv;
        extern FFW_API PFNGLVERTEXATTRIBI4IPROC glVertexAttribI4i;
        extern FFW_API PFNGLVERTEXATTRIBI4IVPROC glVertexAttribI4iv;
        extern FFW_API PFNGLVERTEXATTRIBI4SVPROC glVertexAttribI4sv;
        extern FFW_API PFNGLVERTEXATTRIBI4UBVPROC glVertexAttribI4ubv;
        extern FFW_API PFNGLVERTEXATTRIBI4UIPROC glVertexAttribI4ui;
        extern FFW_API PFNGLVERTEXATTRIBI4UIVPROC glVertexAttribI4uiv;
        extern FFW_API PFNGLVERTEXATTRIBI4USVPROC glVertexAttribI4usv;
        extern FFW_API PFNGLVERTEXATTRIBIPOINTERPROC glVertexAttribIPointer;
#endif /* GL_VERSION_3_0 */

#ifdef GL_VERSION_3_1
        extern FFW_API PFNGLCOPYBUFFERSUBDATAPROC glCopyBufferSubData;
        extern FFW_API PFNGLDRAWARRAYSINSTANCEDPROC glDrawArraysInstanced;
        extern FFW_API PFNGLDRAWELEMENTSINSTANCEDPROC glDrawElementsInstanced;
        extern FFW_API PFNGLGETACTIVEUNIFORMBLOCKIVPROC glGetActiveUniformBlockiv;
        extern FFW_API PFNGLGETACTIVEUNIFORMBLOCKNAMEPROC glGetActiveUniformBlockName;
        extern FFW_API PFNGLGETACTIVEUNIFORMNAMEPROC glGetActiveUniformName;
        extern FFW_API PFNGLGETACTIVEUNIFORMSIVPROC glGetActiveUniformsiv;
        extern FFW_API PFNGLGETUNIFORMBLOCKINDEXPROC glGetUniformBlockIndex;
        extern FFW_API PFNGLGETUNIFORMINDICESPROC glGetUniformIndices;
        extern FFW_API PFNGLPRIMITIVERESTARTINDEXPROC glPrimitiveRestartIndex;
        extern FFW_API PFNGLTEXBUFFERPROC glTexBuffer;
        extern FFW_API PFNGLUNIFORMBLOCKBINDINGPROC glUniformBlockBinding;
#endif /* GL_VERSION_3_1 */

#ifdef GL_VERSION_3_2
        extern FFW_API PFNGLCLIENTWAITSYNCPROC glClientWaitSync;
        extern FFW_API PFNGLDELETESYNCPROC glDeleteSync;
        extern FFW_API PFNGLDRAWELEMENTSBASEVERTEXPROC glDrawElementsBaseVertex;
        extern FFW_API PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXPROC glDrawElementsInstancedBaseVertex;
        extern FFW_API PFNGLDRAWRANGEELEMENTSBASEVERTEXPROC glDrawRangeElementsBaseVertex;
        extern FFW_API PFNGLFENCESYNCPROC glFenceSync;
        extern FFW_API PFNGLFRAMEBUFFERTEXTUREPROC glFramebufferTexture;
        extern FFW_API PFNGLGETBUFFERPARAMETERI64VPROC glGetBufferParameteri64v;
        extern FFW_API PFNGLGETINTEGER64I_VPROC glGetInteger64i_v;
        extern FFW_API PFNGLGETINTEGER64VPROC glGetInteger64v;
        extern FFW_API PFNGLGETMULTISAMPLEFVPROC glGetMultisamplefv;
        extern FFW_API PFNGLGETSYNCIVPROC glGetSynciv;
        extern FFW_API PFNGLISSYNCPROC glIsSync;
        extern FFW_API PFNGLMULTIDRAWELEMENTSBASEVERTEXPROC glMultiDrawElementsBaseVertex;
        extern FFW_API PFNGLPROVOKINGVERTEXPROC glProvokingVertex;
        extern FFW_API PFNGLSAMPLEMASKIPROC glSampleMaski;
        extern FFW_API PFNGLTEXIMAGE2DMULTISAMPLEPROC glTexImage2DMultisample;
        extern FFW_API PFNGLTEXIMAGE3DMULTISAMPLEPROC glTexImage3DMultisample;
        extern FFW_API PFNGLWAITSYNCPROC glWaitSync;
#endif /* GL_VERSION_3_2 */

#ifdef GL_VERSION_3_3
        extern FFW_API PFNGLBINDFRAGDATALOCATIONINDEXEDPROC glBindFragDataLocationIndexed;
        extern FFW_API PFNGLBINDSAMPLERPROC glBindSampler;
        extern FFW_API PFNGLDELETESAMPLERSPROC glDeleteSamplers;
        extern FFW_API PFNGLGENSAMPLERSPROC glGenSamplers;
        extern FFW_API PFNGLGETFRAGDATAINDEXPROC glGetFragDataIndex;
        extern FFW_API PFNGLGETQUERYOBJECTI64VPROC glGetQueryObjecti64v;
        extern FFW_API PFNGLGETQUERYOBJECTUI64VPROC glGetQueryObjectui64v;
        extern FFW_API PFNGLGETSAMPLERPARAMETERFVPROC glGetSamplerParameterfv;
        extern FFW_API PFNGLGETSAMPLERPARAMETERIIVPROC glGetSamplerParameterIiv;
        extern FFW_API PFNGLGETSAMPLERPARAMETERIUIVPROC glGetSamplerParameterIuiv;
        extern FFW_API PFNGLGETSAMPLERPARAMETERIVPROC glGetSamplerParameteriv;
        extern FFW_API PFNGLISSAMPLERPROC glIsSampler;
        extern FFW_API PFNGLQUERYCOUNTERPROC glQueryCounter;
        extern FFW_API PFNGLSAMPLERPARAMETERFPROC glSamplerParameterf;
        extern FFW_API PFNGLSAMPLERPARAMETERFVPROC glSamplerParameterfv;
        extern FFW_API PFNGLSAMPLERPARAMETERIIVPROC glSamplerParameterIiv;
        extern FFW_API PFNGLSAMPLERPARAMETERIPROC glSamplerParameteri;
        extern FFW_API PFNGLSAMPLERPARAMETERIUIVPROC glSamplerParameterIuiv;
        extern FFW_API PFNGLSAMPLERPARAMETERIVPROC glSamplerParameteriv;
        extern FFW_API PFNGLVERTEXATTRIBDIVISORPROC glVertexAttribDivisor;
        extern FFW_API PFNGLVERTEXATTRIBP1UIPROC glVertexAttribP1ui;
        extern FFW_API PFNGLVERTEXATTRIBP1UIVPROC glVertexAttribP1uiv;
        extern FFW_API PFNGLVERTEXATTRIBP2UIPROC glVertexAttribP2ui;
        extern FFW_API PFNGLVERTEXATTRIBP2UIVPROC glVertexAttribP2uiv;
        extern FFW_API PFNGLVERTEXATTRIBP3UIPROC glVertexAttribP3ui;
        extern FFW_API PFNGLVERTEXATTRIBP3UIVPROC glVertexAttribP3uiv;
        extern FFW_API PFNGLVERTEXATTRIBP4UIPROC glVertexAttribP4ui;
        extern FFW_API PFNGLVERTEXATTRIBP4UIVPROC glVertexAttribP4uiv;
#endif /* GL_VERSION_3_3 */

#ifdef GL_VERSION_4_0
        extern FFW_API PFNGLBEGINQUERYINDEXEDPROC glBeginQueryIndexed;
        extern FFW_API PFNGLBINDTRANSFORMFEEDBACKPROC glBindTransformFeedback;
        extern FFW_API PFNGLBLENDEQUATIONIPROC glBlendEquationi;
        extern FFW_API PFNGLBLENDEQUATIONSEPARATEIPROC glBlendEquationSeparatei;
        extern FFW_API PFNGLBLENDFUNCIPROC glBlendFunci;
        extern FFW_API PFNGLBLENDFUNCSEPARATEIPROC glBlendFuncSeparatei;
        extern FFW_API PFNGLDELETETRANSFORMFEEDBACKSPROC glDeleteTransformFeedbacks;
        extern FFW_API PFNGLDRAWARRAYSINDIRECTPROC glDrawArraysIndirect;
        extern FFW_API PFNGLDRAWELEMENTSINDIRECTPROC glDrawElementsIndirect;
        extern FFW_API PFNGLDRAWTRANSFORMFEEDBACKPROC glDrawTransformFeedback;
        extern FFW_API PFNGLDRAWTRANSFORMFEEDBACKSTREAMPROC glDrawTransformFeedbackStream;
        extern FFW_API PFNGLENDQUERYINDEXEDPROC glEndQueryIndexed;
        extern FFW_API PFNGLGENTRANSFORMFEEDBACKSPROC glGenTransformFeedbacks;
        extern FFW_API PFNGLGETACTIVESUBROUTINENAMEPROC glGetActiveSubroutineName;
        extern FFW_API PFNGLGETACTIVESUBROUTINEUNIFORMIVPROC glGetActiveSubroutineUniformiv;
        extern FFW_API PFNGLGETACTIVESUBROUTINEUNIFORMNAMEPROC glGetActiveSubroutineUniformName;
        extern FFW_API PFNGLGETPROGRAMSTAGEIVPROC glGetProgramStageiv;
        extern FFW_API PFNGLGETQUERYINDEXEDIVPROC glGetQueryIndexediv;
        extern FFW_API PFNGLGETSUBROUTINEINDEXPROC glGetSubroutineIndex;
        extern FFW_API PFNGLGETSUBROUTINEUNIFORMLOCATIONPROC glGetSubroutineUniformLocation;
        extern FFW_API PFNGLGETUNIFORMDVPROC glGetUniformdv;
        extern FFW_API PFNGLGETUNIFORMSUBROUTINEUIVPROC glGetUniformSubroutineuiv;
        extern FFW_API PFNGLISTRANSFORMFEEDBACKPROC glIsTransformFeedback;
        extern FFW_API PFNGLMINSAMPLESHADINGPROC glMinSampleShading;
        extern FFW_API PFNGLPATCHPARAMETERFVPROC glPatchParameterfv;
        extern FFW_API PFNGLPATCHPARAMETERIPROC glPatchParameteri;
        extern FFW_API PFNGLPAUSETRANSFORMFEEDBACKPROC glPauseTransformFeedback;
        extern FFW_API PFNGLRESUMETRANSFORMFEEDBACKPROC glResumeTransformFeedback;
        extern FFW_API PFNGLUNIFORM1DPROC glUniform1d;
        extern FFW_API PFNGLUNIFORM1DVPROC glUniform1dv;
        extern FFW_API PFNGLUNIFORM2DPROC glUniform2d;
        extern FFW_API PFNGLUNIFORM2DVPROC glUniform2dv;
        extern FFW_API PFNGLUNIFORM3DPROC glUniform3d;
        extern FFW_API PFNGLUNIFORM3DVPROC glUniform3dv;
        extern FFW_API PFNGLUNIFORM4DPROC glUniform4d;
        extern FFW_API PFNGLUNIFORM4DVPROC glUniform4dv;
        extern FFW_API PFNGLUNIFORMMATRIX2DVPROC glUniformMatrix2dv;
        extern FFW_API PFNGLUNIFORMMATRIX2X3DVPROC glUniformMatrix2x3dv;
        extern FFW_API PFNGLUNIFORMMATRIX2X4DVPROC glUniformMatrix2x4dv;
        extern FFW_API PFNGLUNIFORMMATRIX3DVPROC glUniformMatrix3dv;
        extern FFW_API PFNGLUNIFORMMATRIX3X2DVPROC glUniformMatrix3x2dv;
        extern FFW_API PFNGLUNIFORMMATRIX3X4DVPROC glUniformMatrix3x4dv;
        extern FFW_API PFNGLUNIFORMMATRIX4DVPROC glUniformMatrix4dv;
        extern FFW_API PFNGLUNIFORMMATRIX4X2DVPROC glUniformMatrix4x2dv;
        extern FFW_API PFNGLUNIFORMMATRIX4X3DVPROC glUniformMatrix4x3dv;
        extern FFW_API PFNGLUNIFORMSUBROUTINESUIVPROC glUniformSubroutinesuiv;
#endif /* GL_VERSION_4_0 */

#ifdef GL_VERSION_4_1
        extern FFW_API PFNGLACTIVESHADERPROGRAMPROC glActiveShaderProgram;
        extern FFW_API PFNGLBINDPROGRAMPIPELINEPROC glBindProgramPipeline;
        extern FFW_API PFNGLCLEARDEPTHFPROC glClearDepthf;
        extern FFW_API PFNGLCREATESHADERPROGRAMVPROC glCreateShaderProgramv;
        extern FFW_API PFNGLDELETEPROGRAMPIPELINESPROC glDeleteProgramPipelines;
        extern FFW_API PFNGLDEPTHRANGEARRAYVPROC glDepthRangeArrayv;
        extern FFW_API PFNGLDEPTHRANGEFPROC glDepthRangef;
        extern FFW_API PFNGLDEPTHRANGEINDEXEDPROC glDepthRangeIndexed;
        extern FFW_API PFNGLGENPROGRAMPIPELINESPROC glGenProgramPipelines;
        extern FFW_API PFNGLGETDOUBLEI_VPROC glGetDoublei_v;
        extern FFW_API PFNGLGETFLOATI_VPROC glGetFloati_v;
        extern FFW_API PFNGLGETPROGRAMBINARYPROC glGetProgramBinary;
        extern FFW_API PFNGLGETPROGRAMPIPELINEINFOLOGPROC glGetProgramPipelineInfoLog;
        extern FFW_API PFNGLGETPROGRAMPIPELINEIVPROC glGetProgramPipelineiv;
        extern FFW_API PFNGLGETSHADERPRECISIONFORMATPROC glGetShaderPrecisionFormat;
        extern FFW_API PFNGLGETVERTEXATTRIBLDVPROC glGetVertexAttribLdv;
        extern FFW_API PFNGLISPROGRAMPIPELINEPROC glIsProgramPipeline;
        extern FFW_API PFNGLPROGRAMBINARYPROC glProgramBinary;
        extern FFW_API PFNGLPROGRAMPARAMETERIPROC glProgramParameteri;
        extern FFW_API PFNGLPROGRAMUNIFORM1DPROC glProgramUniform1d;
        extern FFW_API PFNGLPROGRAMUNIFORM1DVPROC glProgramUniform1dv;
        extern FFW_API PFNGLPROGRAMUNIFORM1FPROC glProgramUniform1f;
        extern FFW_API PFNGLPROGRAMUNIFORM1FVPROC glProgramUniform1fv;
        extern FFW_API PFNGLPROGRAMUNIFORM1IPROC glProgramUniform1i;
        extern FFW_API PFNGLPROGRAMUNIFORM1IVPROC glProgramUniform1iv;
        extern FFW_API PFNGLPROGRAMUNIFORM1UIPROC glProgramUniform1ui;
        extern FFW_API PFNGLPROGRAMUNIFORM1UIVPROC glProgramUniform1uiv;
        extern FFW_API PFNGLPROGRAMUNIFORM2DPROC glProgramUniform2d;
        extern FFW_API PFNGLPROGRAMUNIFORM2DVPROC glProgramUniform2dv;
        extern FFW_API PFNGLPROGRAMUNIFORM2FPROC glProgramUniform2f;
        extern FFW_API PFNGLPROGRAMUNIFORM2FVPROC glProgramUniform2fv;
        extern FFW_API PFNGLPROGRAMUNIFORM2IPROC glProgramUniform2i;
        extern FFW_API PFNGLPROGRAMUNIFORM2IVPROC glProgramUniform2iv;
        extern FFW_API PFNGLPROGRAMUNIFORM2UIPROC glProgramUniform2ui;
        extern FFW_API PFNGLPROGRAMUNIFORM2UIVPROC glProgramUniform2uiv;
        extern FFW_API PFNGLPROGRAMUNIFORM3DPROC glProgramUniform3d;
        extern FFW_API PFNGLPROGRAMUNIFORM3DVPROC glProgramUniform3dv;
        extern FFW_API PFNGLPROGRAMUNIFORM3FPROC glProgramUniform3f;
        extern FFW_API PFNGLPROGRAMUNIFORM3FVPROC glProgramUniform3fv;
        extern FFW_API PFNGLPROGRAMUNIFORM3IPROC glProgramUniform3i;
        extern FFW_API PFNGLPROGRAMUNIFORM3IVPROC glProgramUniform3iv;
        extern FFW_API PFNGLPROGRAMUNIFORM3UIPROC glProgramUniform3ui;
        extern FFW_API PFNGLPROGRAMUNIFORM3UIVPROC glProgramUniform3uiv;
        extern FFW_API PFNGLPROGRAMUNIFORM4DPROC glProgramUniform4d;
        extern FFW_API PFNGLPROGRAMUNIFORM4DVPROC glProgramUniform4dv;
        extern FFW_API PFNGLPROGRAMUNIFORM4FPROC glProgramUniform4f;
        extern FFW_API PFNGLPROGRAMUNIFORM4FVPROC glProgramUniform4fv;
        extern FFW_API PFNGLPROGRAMUNIFORM4IPROC glProgramUniform4i;
        extern FFW_API PFNGLPROGRAMUNIFORM4IVPROC glProgramUniform4iv;
        extern FFW_API PFNGLPROGRAMUNIFORM4UIPROC glProgramUniform4ui;
        extern FFW_API PFNGLPROGRAMUNIFORM4UIVPROC glProgramUniform4uiv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX2DVPROC glProgramUniformMatrix2dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX2FVPROC glProgramUniformMatrix2fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX2X3DVPROC glProgramUniformMatrix2x3dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX2X3FVPROC glProgramUniformMatrix2x3fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX2X4DVPROC glProgramUniformMatrix2x4dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX2X4FVPROC glProgramUniformMatrix2x4fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX3DVPROC glProgramUniformMatrix3dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX3FVPROC glProgramUniformMatrix3fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX3X2DVPROC glProgramUniformMatrix3x2dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX3X2FVPROC glProgramUniformMatrix3x2fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX3X4DVPROC glProgramUniformMatrix3x4dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX3X4FVPROC glProgramUniformMatrix3x4fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX4DVPROC glProgramUniformMatrix4dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX4FVPROC glProgramUniformMatrix4fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX4X2DVPROC glProgramUniformMatrix4x2dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX4X2FVPROC glProgramUniformMatrix4x2fv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX4X3DVPROC glProgramUniformMatrix4x3dv;
        extern FFW_API PFNGLPROGRAMUNIFORMMATRIX4X3FVPROC glProgramUniformMatrix4x3fv;
        extern FFW_API PFNGLRELEASESHADERCOMPILERPROC glReleaseShaderCompiler;
        extern FFW_API PFNGLSCISSORARRAYVPROC glScissorArrayv;
        extern FFW_API PFNGLSCISSORINDEXEDPROC glScissorIndexed;
        extern FFW_API PFNGLSCISSORINDEXEDVPROC glScissorIndexedv;
        extern FFW_API PFNGLSHADERBINARYPROC glShaderBinary;
        extern FFW_API PFNGLUSEPROGRAMSTAGESPROC glUseProgramStages;
        extern FFW_API PFNGLVALIDATEPROGRAMPIPELINEPROC glValidateProgramPipeline;
        extern FFW_API PFNGLVERTEXATTRIBL1DPROC glVertexAttribL1d;
        extern FFW_API PFNGLVERTEXATTRIBL1DVPROC glVertexAttribL1dv;
        extern FFW_API PFNGLVERTEXATTRIBL2DPROC glVertexAttribL2d;
        extern FFW_API PFNGLVERTEXATTRIBL2DVPROC glVertexAttribL2dv;
        extern FFW_API PFNGLVERTEXATTRIBL3DPROC glVertexAttribL3d;
        extern FFW_API PFNGLVERTEXATTRIBL3DVPROC glVertexAttribL3dv;
        extern FFW_API PFNGLVERTEXATTRIBL4DPROC glVertexAttribL4d;
        extern FFW_API PFNGLVERTEXATTRIBL4DVPROC glVertexAttribL4dv;
        extern FFW_API PFNGLVERTEXATTRIBLPOINTERPROC glVertexAttribLPointer;
        extern FFW_API PFNGLVIEWPORTARRAYVPROC glViewportArrayv;
        extern FFW_API PFNGLVIEWPORTINDEXEDFPROC glViewportIndexedf;
        extern FFW_API PFNGLVIEWPORTINDEXEDFVPROC glViewportIndexedfv;
#endif /* GL_VERSION_4_1 */

#ifdef GL_VERSION_4_2
        extern FFW_API PFNGLBINDIMAGETEXTUREPROC glBindImageTexture;
        extern FFW_API PFNGLDRAWARRAYSINSTANCEDBASEINSTANCEPROC glDrawArraysInstancedBaseInstance;
        extern FFW_API PFNGLDRAWELEMENTSINSTANCEDBASEINSTANCEPROC glDrawElementsInstancedBaseInstance;
        extern FFW_API PFNGLDRAWELEMENTSINSTANCEDBASEVERTEXBASEINSTANCEPROC glDrawElementsInstancedBaseVertexBaseInstance;
        extern FFW_API PFNGLDRAWTRANSFORMFEEDBACKINSTANCEDPROC glDrawTransformFeedbackInstanced;
        extern FFW_API PFNGLDRAWTRANSFORMFEEDBACKSTREAMINSTANCEDPROC glDrawTransformFeedbackStreamInstanced;
        extern FFW_API PFNGLGETACTIVEATOMICCOUNTERBUFFERIVPROC glGetActiveAtomicCounterBufferiv;
        extern FFW_API PFNGLGETINTERNALFORMATIVPROC glGetInternalformativ;
        extern FFW_API PFNGLMEMORYBARRIERPROC glMemoryBarrier;
        extern FFW_API PFNGLTEXSTORAGE1DPROC glTexStorage1D;
        extern FFW_API PFNGLTEXSTORAGE2DPROC glTexStorage2D;
        extern FFW_API PFNGLTEXSTORAGE3DPROC glTexStorage3D;
#endif /* GL_VERSION_4_2 */

#ifdef GL_VERSION_4_3
        extern FFW_API PFNGLBINDVERTEXBUFFERPROC glBindVertexBuffer;
        extern FFW_API PFNGLCLEARBUFFERDATAPROC glClearBufferData;
        extern FFW_API PFNGLCLEARBUFFERSUBDATAPROC glClearBufferSubData;
        extern FFW_API PFNGLCOPYIMAGESUBDATAPROC glCopyImageSubData;
        extern FFW_API PFNGLDEBUGMESSAGECALLBACKPROC glDebugMessageCallback;
        extern FFW_API PFNGLDEBUGMESSAGECONTROLPROC glDebugMessageControl;
        extern FFW_API PFNGLDEBUGMESSAGEINSERTPROC glDebugMessageInsert;
        extern FFW_API PFNGLDISPATCHCOMPUTEINDIRECTPROC glDispatchComputeIndirect;
        extern FFW_API PFNGLDISPATCHCOMPUTEPROC glDispatchCompute;
        extern FFW_API PFNGLFRAMEBUFFERPARAMETERIPROC glFramebufferParameteri;
        extern FFW_API PFNGLGETDEBUGMESSAGELOGPROC glGetDebugMessageLog;
        extern FFW_API PFNGLGETFRAMEBUFFERPARAMETERIVPROC glGetFramebufferParameteriv;
        extern FFW_API PFNGLGETINTERNALFORMATI64VPROC glGetInternalformati64v;
        extern FFW_API PFNGLGETOBJECTLABELPROC glGetObjectLabel;
        extern FFW_API PFNGLGETOBJECTPTRLABELPROC glGetObjectPtrLabel;
        extern FFW_API PFNGLGETPROGRAMINTERFACEIVPROC glGetProgramInterfaceiv;
        extern FFW_API PFNGLGETPROGRAMRESOURCEINDEXPROC glGetProgramResourceIndex;
        extern FFW_API PFNGLGETPROGRAMRESOURCEIVPROC glGetProgramResourceiv;
        extern FFW_API PFNGLGETPROGRAMRESOURCELOCATIONINDEXPROC glGetProgramResourceLocationIndex;
        extern FFW_API PFNGLGETPROGRAMRESOURCELOCATIONPROC glGetProgramResourceLocation;
        extern FFW_API PFNGLGETPROGRAMRESOURCENAMEPROC glGetProgramResourceName;
        extern FFW_API PFNGLINVALIDATEBUFFERDATAPROC glInvalidateBufferData;
        extern FFW_API PFNGLINVALIDATEBUFFERSUBDATAPROC glInvalidateBufferSubData;
        extern FFW_API PFNGLINVALIDATEFRAMEBUFFERPROC glInvalidateFramebuffer;
        extern FFW_API PFNGLINVALIDATESUBFRAMEBUFFERPROC glInvalidateSubFramebuffer;
        extern FFW_API PFNGLINVALIDATETEXIMAGEPROC glInvalidateTexImage;
        extern FFW_API PFNGLINVALIDATETEXSUBIMAGEPROC glInvalidateTexSubImage;
        extern FFW_API PFNGLMULTIDRAWARRAYSINDIRECTPROC glMultiDrawArraysIndirect;
        extern FFW_API PFNGLMULTIDRAWELEMENTSINDIRECTPROC glMultiDrawElementsIndirect;
        extern FFW_API PFNGLOBJECTLABELPROC glObjectLabel;
        extern FFW_API PFNGLOBJECTPTRLABELPROC glObjectPtrLabel;
        extern FFW_API PFNGLPOPDEBUGGROUPPROC glPopDebugGroup;
        extern FFW_API PFNGLPUSHDEBUGGROUPPROC glPushDebugGroup;
        extern FFW_API PFNGLSHADERSTORAGEBLOCKBINDINGPROC glShaderStorageBlockBinding;
        extern FFW_API PFNGLTEXBUFFERRANGEPROC glTexBufferRange;
        extern FFW_API PFNGLTEXSTORAGE2DMULTISAMPLEPROC glTexStorage2DMultisample;
        extern FFW_API PFNGLTEXSTORAGE3DMULTISAMPLEPROC glTexStorage3DMultisample;
        extern FFW_API PFNGLTEXTUREVIEWPROC glTextureView;
        extern FFW_API PFNGLVERTEXATTRIBBINDINGPROC glVertexAttribBinding;
        extern FFW_API PFNGLVERTEXATTRIBFORMATPROC glVertexAttribFormat;
        extern FFW_API PFNGLVERTEXATTRIBIFORMATPROC glVertexAttribIFormat;
        extern FFW_API PFNGLVERTEXATTRIBLFORMATPROC glVertexAttribLFormat;
        extern FFW_API PFNGLVERTEXBINDINGDIVISORPROC glVertexBindingDivisor;
#endif /* GL_VERSION_4_3 */

#ifdef GL_VERSION_4_4
        extern FFW_API PFNGLBINDBUFFERSBASEPROC glBindBuffersBase;
        extern FFW_API PFNGLBINDBUFFERSRANGEPROC glBindBuffersRange;
        extern FFW_API PFNGLBINDIMAGETEXTURESPROC glBindImageTextures;
        extern FFW_API PFNGLBINDSAMPLERSPROC glBindSamplers;
        extern FFW_API PFNGLBINDTEXTURESPROC glBindTextures;
        extern FFW_API PFNGLBINDVERTEXBUFFERSPROC glBindVertexBuffers;
        extern FFW_API PFNGLBUFFERSTORAGEPROC glBufferStorage;
        extern FFW_API PFNGLCLEARTEXIMAGEPROC glClearTexImage;
        extern FFW_API PFNGLCLEARTEXSUBIMAGEPROC glClearTexSubImage;
#endif /* GL_VERSION_4_4 */

#ifdef GL_VERSION_4_5
        extern FFW_API PFNGLBINDTEXTUREUNITPROC glBindTextureUnit;
        extern FFW_API PFNGLBLITNAMEDFRAMEBUFFERPROC glBlitNamedFramebuffer;
        extern FFW_API PFNGLCHECKNAMEDFRAMEBUFFERSTATUSPROC glCheckNamedFramebufferStatus;
        extern FFW_API PFNGLCLEARNAMEDBUFFERDATAPROC glClearNamedBufferData;
        extern FFW_API PFNGLCLEARNAMEDBUFFERSUBDATAPROC glClearNamedBufferSubData;
        extern FFW_API PFNGLCLEARNAMEDFRAMEBUFFERFIPROC glClearNamedFramebufferfi;
        extern FFW_API PFNGLCLEARNAMEDFRAMEBUFFERFVPROC glClearNamedFramebufferfv;
        extern FFW_API PFNGLCLEARNAMEDFRAMEBUFFERIVPROC glClearNamedFramebufferiv;
        extern FFW_API PFNGLCLEARNAMEDFRAMEBUFFERUIVPROC glClearNamedFramebufferuiv;
        extern FFW_API PFNGLCLIPCONTROLPROC glClipControl;
        extern FFW_API PFNGLCOMPRESSEDTEXTURESUBIMAGE1DPROC glCompressedTextureSubImage1D;
        extern FFW_API PFNGLCOMPRESSEDTEXTURESUBIMAGE2DPROC glCompressedTextureSubImage2D;
        extern FFW_API PFNGLCOMPRESSEDTEXTURESUBIMAGE3DPROC glCompressedTextureSubImage3D;
        extern FFW_API PFNGLCOPYNAMEDBUFFERSUBDATAPROC glCopyNamedBufferSubData;
        extern FFW_API PFNGLCOPYTEXTURESUBIMAGE1DPROC glCopyTextureSubImage1D;
        extern FFW_API PFNGLCOPYTEXTURESUBIMAGE2DPROC glCopyTextureSubImage2D;
        extern FFW_API PFNGLCOPYTEXTURESUBIMAGE3DPROC glCopyTextureSubImage3D;
        extern FFW_API PFNGLCREATEBUFFERSPROC glCreateBuffers;
        extern FFW_API PFNGLCREATEFRAMEBUFFERSPROC glCreateFramebuffers;
        extern FFW_API PFNGLCREATEPROGRAMPIPELINESPROC glCreateProgramPipelines;
        extern FFW_API PFNGLCREATEQUERIESPROC glCreateQueries;
        extern FFW_API PFNGLCREATERENDERBUFFERSPROC glCreateRenderbuffers;
        extern FFW_API PFNGLCREATESAMPLERSPROC glCreateSamplers;
        extern FFW_API PFNGLCREATETEXTURESPROC glCreateTextures;
        extern FFW_API PFNGLCREATETRANSFORMFEEDBACKSPROC glCreateTransformFeedbacks;
        extern FFW_API PFNGLCREATEVERTEXARRAYSPROC glCreateVertexArrays;
        extern FFW_API PFNGLDISABLEVERTEXARRAYATTRIBPROC glDisableVertexArrayAttrib;
        extern FFW_API PFNGLENABLEVERTEXARRAYATTRIBPROC glEnableVertexArrayAttrib;
        extern FFW_API PFNGLFLUSHMAPPEDNAMEDBUFFERRANGEPROC glFlushMappedNamedBufferRange;
        extern FFW_API PFNGLGENERATETEXTUREMIPMAPPROC glGenerateTextureMipmap;
        extern FFW_API PFNGLGETCOMPRESSEDTEXTUREIMAGEPROC glGetCompressedTextureImage;
        extern FFW_API PFNGLGETCOMPRESSEDTEXTURESUBIMAGEPROC glGetCompressedTextureSubImage;
        extern FFW_API PFNGLGETGRAPHICSRESETSTATUSPROC glGetGraphicsResetStatus;
        extern FFW_API PFNGLGETNAMEDBUFFERPARAMETERI64VPROC glGetNamedBufferParameteri64v;
        extern FFW_API PFNGLGETNAMEDBUFFERPARAMETERIVPROC glGetNamedBufferParameteriv;
        extern FFW_API PFNGLGETNAMEDBUFFERPOINTERVPROC glGetNamedBufferPointerv;
        extern FFW_API PFNGLGETNAMEDBUFFERSUBDATAPROC glGetNamedBufferSubData;
        extern FFW_API PFNGLGETNAMEDFRAMEBUFFERATTACHMENTPARAMETERIVPROC glGetNamedFramebufferAttachmentParameteriv;
        extern FFW_API PFNGLGETNAMEDFRAMEBUFFERPARAMETERIVPROC glGetNamedFramebufferParameteriv;
        extern FFW_API PFNGLGETNAMEDRENDERBUFFERPARAMETERIVPROC glGetNamedRenderbufferParameteriv;
        extern FFW_API PFNGLGETNCOMPRESSEDTEXIMAGEPROC glGetnCompressedTexImage;
        extern FFW_API PFNGLGETNTEXIMAGEPROC glGetnTexImage;
        extern FFW_API PFNGLGETNUNIFORMDVPROC glGetnUniformdv;
        extern FFW_API PFNGLGETNUNIFORMFVPROC glGetnUniformfv;
        extern FFW_API PFNGLGETNUNIFORMIVPROC glGetnUniformiv;
        extern FFW_API PFNGLGETNUNIFORMUIVPROC glGetnUniformuiv;
#ifdef FFW_WINDOWS
        extern FFW_API PFNGLGETQUERYBUFFEROBJECTI64VPROC glGetQueryBufferObjecti64v;
        extern FFW_API PFNGLGETQUERYBUFFEROBJECTIVPROC glGetQueryBufferObjectiv;
        extern FFW_API PFNGLGETQUERYBUFFEROBJECTUI64VPROC glGetQueryBufferObjectui64v;
        extern FFW_API PFNGLGETQUERYBUFFEROBJECTUIVPROC glGetQueryBufferObjectuiv;
#endif
        extern FFW_API PFNGLGETTEXTUREIMAGEPROC glGetTextureImage;
        extern FFW_API PFNGLGETTEXTURELEVELPARAMETERFVPROC glGetTextureLevelParameterfv;
        extern FFW_API PFNGLGETTEXTURELEVELPARAMETERIVPROC glGetTextureLevelParameteriv;
        extern FFW_API PFNGLGETTEXTUREPARAMETERFVPROC glGetTextureParameterfv;
        extern FFW_API PFNGLGETTEXTUREPARAMETERIIVPROC glGetTextureParameterIiv;
        extern FFW_API PFNGLGETTEXTUREPARAMETERIUIVPROC glGetTextureParameterIuiv;
        extern FFW_API PFNGLGETTEXTUREPARAMETERIVPROC glGetTextureParameteriv;
        extern FFW_API PFNGLGETTEXTURESUBIMAGEPROC glGetTextureSubImage;
        extern FFW_API PFNGLGETTRANSFORMFEEDBACKI64_VPROC glGetTransformFeedbacki64_v;
        extern FFW_API PFNGLGETTRANSFORMFEEDBACKIVPROC glGetTransformFeedbackiv;
        extern FFW_API PFNGLGETTRANSFORMFEEDBACKI_VPROC glGetTransformFeedbacki_v;
        extern FFW_API PFNGLGETVERTEXARRAYINDEXED64IVPROC glGetVertexArrayIndexed64iv;
        extern FFW_API PFNGLGETVERTEXARRAYINDEXEDIVPROC glGetVertexArrayIndexediv;
        extern FFW_API PFNGLGETVERTEXARRAYIVPROC glGetVertexArrayiv;
        extern FFW_API PFNGLINVALIDATENAMEDFRAMEBUFFERDATAPROC glInvalidateNamedFramebufferData;
        extern FFW_API PFNGLINVALIDATENAMEDFRAMEBUFFERSUBDATAPROC glInvalidateNamedFramebufferSubData;
        extern FFW_API PFNGLMAPNAMEDBUFFERPROC glMapNamedBuffer;
        extern FFW_API PFNGLMAPNAMEDBUFFERRANGEPROC glMapNamedBufferRange;
        extern FFW_API PFNGLMEMORYBARRIERBYREGIONPROC glMemoryBarrierByRegion;
        extern FFW_API PFNGLNAMEDBUFFERDATAPROC glNamedBufferData;
        extern FFW_API PFNGLNAMEDBUFFERSTORAGEPROC glNamedBufferStorage;
        extern FFW_API PFNGLNAMEDBUFFERSUBDATAPROC glNamedBufferSubData;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERDRAWBUFFERPROC glNamedFramebufferDrawBuffer;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERDRAWBUFFERSPROC glNamedFramebufferDrawBuffers;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERPARAMETERIPROC glNamedFramebufferParameteri;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERREADBUFFERPROC glNamedFramebufferReadBuffer;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERRENDERBUFFERPROC glNamedFramebufferRenderbuffer;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERTEXTURELAYERPROC glNamedFramebufferTextureLayer;
        extern FFW_API PFNGLNAMEDFRAMEBUFFERTEXTUREPROC glNamedFramebufferTexture;
        extern FFW_API PFNGLNAMEDRENDERBUFFERSTORAGEMULTISAMPLEPROC glNamedRenderbufferStorageMultisample;
        extern FFW_API PFNGLNAMEDRENDERBUFFERSTORAGEPROC glNamedRenderbufferStorage;
        extern FFW_API PFNGLREADNPIXELSPROC glReadnPixels;
        extern FFW_API PFNGLTEXTUREBARRIERPROC glTextureBarrier;
        extern FFW_API PFNGLTEXTUREBUFFERPROC glTextureBuffer;
        extern FFW_API PFNGLTEXTUREBUFFERRANGEPROC glTextureBufferRange;
        extern FFW_API PFNGLTEXTUREPARAMETERFPROC glTextureParameterf;
        extern FFW_API PFNGLTEXTUREPARAMETERFVPROC glTextureParameterfv;
        extern FFW_API PFNGLTEXTUREPARAMETERIIVPROC glTextureParameterIiv;
        extern FFW_API PFNGLTEXTUREPARAMETERIPROC glTextureParameteri;
        extern FFW_API PFNGLTEXTUREPARAMETERIUIVPROC glTextureParameterIuiv;
        extern FFW_API PFNGLTEXTUREPARAMETERIVPROC glTextureParameteriv;
        extern FFW_API PFNGLTEXTURESTORAGE1DPROC glTextureStorage1D;
        extern FFW_API PFNGLTEXTURESTORAGE2DMULTISAMPLEPROC glTextureStorage2DMultisample;
        extern FFW_API PFNGLTEXTURESTORAGE2DPROC glTextureStorage2D;
        extern FFW_API PFNGLTEXTURESTORAGE3DMULTISAMPLEPROC glTextureStorage3DMultisample;
        extern FFW_API PFNGLTEXTURESTORAGE3DPROC glTextureStorage3D;
        extern FFW_API PFNGLTEXTURESUBIMAGE1DPROC glTextureSubImage1D;
        extern FFW_API PFNGLTEXTURESUBIMAGE2DPROC glTextureSubImage2D;
        extern FFW_API PFNGLTEXTURESUBIMAGE3DPROC glTextureSubImage3D;
        extern FFW_API PFNGLTRANSFORMFEEDBACKBUFFERBASEPROC glTransformFeedbackBufferBase;
        extern FFW_API PFNGLTRANSFORMFEEDBACKBUFFERRANGEPROC glTransformFeedbackBufferRange;
        extern FFW_API PFNGLUNMAPNAMEDBUFFERPROC glUnmapNamedBuffer;
        extern FFW_API PFNGLVERTEXARRAYATTRIBBINDINGPROC glVertexArrayAttribBinding;
        extern FFW_API PFNGLVERTEXARRAYATTRIBFORMATPROC glVertexArrayAttribFormat;
        extern FFW_API PFNGLVERTEXARRAYATTRIBIFORMATPROC glVertexArrayAttribIFormat;
        extern FFW_API PFNGLVERTEXARRAYATTRIBLFORMATPROC glVertexArrayAttribLFormat;
        extern FFW_API PFNGLVERTEXARRAYBINDINGDIVISORPROC glVertexArrayBindingDivisor;
        extern FFW_API PFNGLVERTEXARRAYELEMENTBUFFERPROC glVertexArrayElementBuffer;
        extern FFW_API PFNGLVERTEXARRAYVERTEXBUFFERPROC glVertexArrayVertexBuffer;
        extern FFW_API PFNGLVERTEXARRAYVERTEXBUFFERSPROC glVertexArrayVertexBuffers;
#endif /* GL_VERSION_4_5 */

#ifdef GL_VERSION_4_6
        extern FFW_API PFNGLMULTIDRAWARRAYSINDIRECTCOUNTPROC glMultiDrawArraysIndirectCount;
        extern FFW_API PFNGLMULTIDRAWELEMENTSINDIRECTCOUNTPROC glMultiDrawElementsIndirectCount;
        extern FFW_API PFNGLPOLYGONOFFSETCLAMPPROC glPolygonOffsetClamp;
        extern FFW_API PFNGLSPECIALIZESHADERPROC glSpecializeShader;
#endif /* GL_VERSION_4_6 */

    }

    void loadGlCoreArb(void* (*glextLoader)(const char*));
};

#ifdef FFW_WINDOWS
#ifdef FFW_WINGDIAPI_DEFINED
#undef WINGDIAPI
#undef APIENTRY
#endif
#endif

// If you wish not to define the following GL defines, add #define FFW_DO_NOT_EXPORT_GL 1 into your program
#ifndef FFW_DO_NOT_EXPORT_GL_PROC
#ifdef GL_VERSION_1_2
#define glCopyTexSubImage3D ffw::gl::glCopyTexSubImage3D
#define glDrawRangeElements ffw::gl::glDrawRangeElements
#define glTexImage3D ffw::gl::glTexImage3D
#define glTexSubImage3D ffw::gl::glTexSubImage3D
#endif /* GL_VERSION_1_2 */

#ifdef GL_VERSION_1_3
#define glActiveTexture ffw::gl::glActiveTexture
#define glCompressedTexImage1D ffw::gl::glCompressedTexImage1D
#define glCompressedTexImage2D ffw::gl::glCompressedTexImage2D
#define glCompressedTexImage3D ffw::gl::glCompressedTexImage3D
#define glCompressedTexSubImage1D ffw::gl::glCompressedTexSubImage1D
#define glCompressedTexSubImage2D ffw::gl::glCompressedTexSubImage2D
#define glCompressedTexSubImage3D ffw::gl::glCompressedTexSubImage3D
#define glGetCompressedTexImage ffw::gl::glGetCompressedTexImage
#define glSampleCoverage ffw::gl::glSampleCoverage
#endif /* GL_VERSION_1_3 */

#ifdef GL_VERSION_1_4
#define glBlendColor ffw::gl::glBlendColor
#define glBlendEquation ffw::gl::glBlendEquation
#define glBlendFuncSeparate ffw::gl::glBlendFuncSeparate
#define glMultiDrawArrays ffw::gl::glMultiDrawArrays
#define glMultiDrawElements ffw::gl::glMultiDrawElements
#define glPointParameterf ffw::gl::glPointParameterf
#define glPointParameterfv ffw::gl::glPointParameterfv
#define glPointParameteri ffw::gl::glPointParameteri
#define glPointParameteriv ffw::gl::glPointParameteriv
#endif /* GL_VERSION_1_4 */

#ifdef GL_VERSION_1_5
#define glBeginQuery ffw::gl::glBeginQuery
#define glBindBuffer ffw::gl::glBindBuffer
#define glBufferData ffw::gl::glBufferData
#define glBufferSubData ffw::gl::glBufferSubData
#define glDeleteBuffers ffw::gl::glDeleteBuffers
#define glDeleteQueries ffw::gl::glDeleteQueries
#define glEndQuery ffw::gl::glEndQuery
#define glGenBuffers ffw::gl::glGenBuffers
#define glGenQueries ffw::gl::glGenQueries
#define glGetBufferParameteriv ffw::gl::glGetBufferParameteriv
#define glGetBufferPointerv ffw::gl::glGetBufferPointerv
#define glGetBufferSubData ffw::gl::glGetBufferSubData
#define glGetQueryiv ffw::gl::glGetQueryiv
#define glGetQueryObjectiv ffw::gl::glGetQueryObjectiv
#define glGetQueryObjectuiv ffw::gl::glGetQueryObjectuiv
#define glIsBuffer ffw::gl::glIsBuffer
#define glIsQuery ffw::gl::glIsQuery
#define glMapBuffer ffw::gl::glMapBuffer
#define glUnmapBuffer ffw::gl::glUnmapBuffer
#endif /* GL_VERSION_1_5 */

#ifdef GL_VERSION_2_0
#define glAttachShader ffw::gl::glAttachShader
#define glBindAttribLocation ffw::gl::glBindAttribLocation
#define glBlendEquationSeparate ffw::gl::glBlendEquationSeparate
#define glCompileShader ffw::gl::glCompileShader
#define glCreateProgram ffw::gl::glCreateProgram
#define glCreateShader ffw::gl::glCreateShader
#define glDeleteProgram ffw::gl::glDeleteProgram
#define glDeleteShader ffw::gl::glDeleteShader
#define glDetachShader ffw::gl::glDetachShader
#define glDisableVertexAttribArray ffw::gl::glDisableVertexAttribArray
#define glDrawBuffers ffw::gl::glDrawBuffers
#define glEnableVertexAttribArray ffw::gl::glEnableVertexAttribArray
#define glGetActiveAttrib ffw::gl::glGetActiveAttrib
#define glGetActiveUniform ffw::gl::glGetActiveUniform
#define glGetAttachedShaders ffw::gl::glGetAttachedShaders
#define glGetAttribLocation ffw::gl::glGetAttribLocation
#define glGetProgramInfoLog ffw::gl::glGetProgramInfoLog
#define glGetProgramiv ffw::gl::glGetProgramiv
#define glGetShaderInfoLog ffw::gl::glGetShaderInfoLog
#define glGetShaderiv ffw::gl::glGetShaderiv
#define glGetShaderSource ffw::gl::glGetShaderSource
#define glGetUniformfv ffw::gl::glGetUniformfv
#define glGetUniformiv ffw::gl::glGetUniformiv
#define glGetUniformLocation ffw::gl::glGetUniformLocation
#define glGetVertexAttribdv ffw::gl::glGetVertexAttribdv
#define glGetVertexAttribfv ffw::gl::glGetVertexAttribfv
#define glGetVertexAttribiv ffw::gl::glGetVertexAttribiv
#define glGetVertexAttribPointerv ffw::gl::glGetVertexAttribPointerv
#define glIsProgram ffw::gl::glIsProgram
#define glIsShader ffw::gl::glIsShader
#define glLinkProgram ffw::gl::glLinkProgram
#define glShaderSource ffw::gl::glShaderSource
#define glStencilFuncSeparate ffw::gl::glStencilFuncSeparate
#define glStencilMaskSeparate ffw::gl::glStencilMaskSeparate
#define glStencilOpSeparate ffw::gl::glStencilOpSeparate
#define glUniform1f ffw::gl::glUniform1f
#define glUniform1fv ffw::gl::glUniform1fv
#define glUniform1i ffw::gl::glUniform1i
#define glUniform1iv ffw::gl::glUniform1iv
#define glUniform2f ffw::gl::glUniform2f
#define glUniform2fv ffw::gl::glUniform2fv
#define glUniform2i ffw::gl::glUniform2i
#define glUniform2iv ffw::gl::glUniform2iv
#define glUniform3f ffw::gl::glUniform3f
#define glUniform3fv ffw::gl::glUniform3fv
#define glUniform3i ffw::gl::glUniform3i
#define glUniform3iv ffw::gl::glUniform3iv
#define glUniform4f ffw::gl::glUniform4f
#define glUniform4fv ffw::gl::glUniform4fv
#define glUniform4i ffw::gl::glUniform4i
#define glUniform4iv ffw::gl::glUniform4iv
#define glUniformMatrix2fv ffw::gl::glUniformMatrix2fv
#define glUniformMatrix3fv ffw::gl::glUniformMatrix3fv
#define glUniformMatrix4fv ffw::gl::glUniformMatrix4fv
#define glUseProgram ffw::gl::glUseProgram
#define glValidateProgram ffw::gl::glValidateProgram
#define glVertexAttrib1d ffw::gl::glVertexAttrib1d
#define glVertexAttrib1dv ffw::gl::glVertexAttrib1dv
#define glVertexAttrib1f ffw::gl::glVertexAttrib1f
#define glVertexAttrib1fv ffw::gl::glVertexAttrib1fv
#define glVertexAttrib1s ffw::gl::glVertexAttrib1s
#define glVertexAttrib1sv ffw::gl::glVertexAttrib1sv
#define glVertexAttrib2d ffw::gl::glVertexAttrib2d
#define glVertexAttrib2dv ffw::gl::glVertexAttrib2dv
#define glVertexAttrib2f ffw::gl::glVertexAttrib2f
#define glVertexAttrib2fv ffw::gl::glVertexAttrib2fv
#define glVertexAttrib2s ffw::gl::glVertexAttrib2s
#define glVertexAttrib2sv ffw::gl::glVertexAttrib2sv
#define glVertexAttrib3d ffw::gl::glVertexAttrib3d
#define glVertexAttrib3dv ffw::gl::glVertexAttrib3dv
#define glVertexAttrib3f ffw::gl::glVertexAttrib3f
#define glVertexAttrib3fv ffw::gl::glVertexAttrib3fv
#define glVertexAttrib3s ffw::gl::glVertexAttrib3s
#define glVertexAttrib3sv ffw::gl::glVertexAttrib3sv
#define glVertexAttrib4bv ffw::gl::glVertexAttrib4bv
#define glVertexAttrib4d ffw::gl::glVertexAttrib4d
#define glVertexAttrib4dv ffw::gl::glVertexAttrib4dv
#define glVertexAttrib4f ffw::gl::glVertexAttrib4f
#define glVertexAttrib4fv ffw::gl::glVertexAttrib4fv
#define glVertexAttrib4iv ffw::gl::glVertexAttrib4iv
#define glVertexAttrib4Nbv ffw::gl::glVertexAttrib4Nbv
#define glVertexAttrib4Niv ffw::gl::glVertexAttrib4Niv
#define glVertexAttrib4Nsv ffw::gl::glVertexAttrib4Nsv
#define glVertexAttrib4Nub ffw::gl::glVertexAttrib4Nub
#define glVertexAttrib4Nubv ffw::gl::glVertexAttrib4Nubv
#define glVertexAttrib4Nuiv ffw::gl::glVertexAttrib4Nuiv
#define glVertexAttrib4Nusv ffw::gl::glVertexAttrib4Nusv
#define glVertexAttrib4s ffw::gl::glVertexAttrib4s
#define glVertexAttrib4sv ffw::gl::glVertexAttrib4sv
#define glVertexAttrib4ubv ffw::gl::glVertexAttrib4ubv
#define glVertexAttrib4uiv ffw::gl::glVertexAttrib4uiv
#define glVertexAttrib4usv ffw::gl::glVertexAttrib4usv
#define glVertexAttribPointer ffw::gl::glVertexAttribPointer
#endif /* GL_VERSION_2_0 */

#ifdef GL_VERSION_2_1
#define glUniformMatrix2x3fv ffw::gl::glUniformMatrix2x3fv
#define glUniformMatrix2x4fv ffw::gl::glUniformMatrix2x4fv
#define glUniformMatrix3x2fv ffw::gl::glUniformMatrix3x2fv
#define glUniformMatrix3x4fv ffw::gl::glUniformMatrix3x4fv
#define glUniformMatrix4x2fv ffw::gl::glUniformMatrix4x2fv
#define glUniformMatrix4x3fv ffw::gl::glUniformMatrix4x3fv
#endif /* GL_VERSION_2_1 */

#ifdef GL_VERSION_3_0
#define glBeginConditionalRender ffw::gl::glBeginConditionalRender
#define glBeginTransformFeedback ffw::gl::glBeginTransformFeedback
#define glBindBufferBase ffw::gl::glBindBufferBase
#define glBindBufferRange ffw::gl::glBindBufferRange
#define glBindFragDataLocation ffw::gl::glBindFragDataLocation
#define glBindFramebuffer ffw::gl::glBindFramebuffer
#define glBindRenderbuffer ffw::gl::glBindRenderbuffer
#define glBindVertexArray ffw::gl::glBindVertexArray
#define glBlitFramebuffer ffw::gl::glBlitFramebuffer
#define glCheckFramebufferStatus ffw::gl::glCheckFramebufferStatus
#define glClampColor ffw::gl::glClampColor
#define glClearBufferfi ffw::gl::glClearBufferfi
#define glClearBufferfv ffw::gl::glClearBufferfv
#define glClearBufferiv ffw::gl::glClearBufferiv
#define glClearBufferuiv ffw::gl::glClearBufferuiv
#define glColorMaski ffw::gl::glColorMaski
#define glDeleteFramebuffers ffw::gl::glDeleteFramebuffers
#define glDeleteRenderbuffers ffw::gl::glDeleteRenderbuffers
#define glDeleteVertexArrays ffw::gl::glDeleteVertexArrays
#define glDisablei ffw::gl::glDisablei
#define glEnablei ffw::gl::glEnablei
#define glEndConditionalRender ffw::gl::glEndConditionalRender
#define glEndTransformFeedback ffw::gl::glEndTransformFeedback
#define glFlushMappedBufferRange ffw::gl::glFlushMappedBufferRange
#define glFramebufferRenderbuffer ffw::gl::glFramebufferRenderbuffer
#define glFramebufferTexture1D ffw::gl::glFramebufferTexture1D
#define glFramebufferTexture2D ffw::gl::glFramebufferTexture2D
#define glFramebufferTexture3D ffw::gl::glFramebufferTexture3D
#define glFramebufferTextureLayer ffw::gl::glFramebufferTextureLayer
#define glGenerateMipmap ffw::gl::glGenerateMipmap
#define glGenFramebuffers ffw::gl::glGenFramebuffers
#define glGenRenderbuffers ffw::gl::glGenRenderbuffers
#define glGenVertexArrays ffw::gl::glGenVertexArrays
#define glGetBooleani_v ffw::gl::glGetBooleani_v
#define glGetFragDataLocation ffw::gl::glGetFragDataLocation
#define glGetFramebufferAttachmentParameteriv ffw::gl::glGetFramebufferAttachmentParameteriv
#define glGetIntegeri_v ffw::gl::glGetIntegeri_v
#define glGetRenderbufferParameteriv ffw::gl::glGetRenderbufferParameteriv
#define glGetStringi ffw::gl::glGetStringi
#define glGetTexParameterIiv ffw::gl::glGetTexParameterIiv
#define glGetTexParameterIuiv ffw::gl::glGetTexParameterIuiv
#define glGetTransformFeedbackVarying ffw::gl::glGetTransformFeedbackVarying
#define glGetUniformuiv ffw::gl::glGetUniformuiv
#define glGetVertexAttribIiv ffw::gl::glGetVertexAttribIiv
#define glGetVertexAttribIuiv ffw::gl::glGetVertexAttribIuiv
#define glIsEnabledi ffw::gl::glIsEnabledi
#define glIsFramebuffer ffw::gl::glIsFramebuffer
#define glIsRenderbuffer ffw::gl::glIsRenderbuffer
#define glIsVertexArray ffw::gl::glIsVertexArray
#define glMapBufferRange ffw::gl::glMapBufferRange
#define glRenderbufferStorageMultisample ffw::gl::glRenderbufferStorageMultisample
#define glRenderbufferStorage ffw::gl::glRenderbufferStorage
#define glTexParameterIiv ffw::gl::glTexParameterIiv
#define glTexParameterIuiv ffw::gl::glTexParameterIuiv
#define glTransformFeedbackVaryings ffw::gl::glTransformFeedbackVaryings
#define glUniform1ui ffw::gl::glUniform1ui
#define glUniform1uiv ffw::gl::glUniform1uiv
#define glUniform2ui ffw::gl::glUniform2ui
#define glUniform2uiv ffw::gl::glUniform2uiv
#define glUniform3ui ffw::gl::glUniform3ui
#define glUniform3uiv ffw::gl::glUniform3uiv
#define glUniform4ui ffw::gl::glUniform4ui
#define glUniform4uiv ffw::gl::glUniform4uiv
#define glVertexAttribI1i ffw::gl::glVertexAttribI1i
#define glVertexAttribI1iv ffw::gl::glVertexAttribI1iv
#define glVertexAttribI1ui ffw::gl::glVertexAttribI1ui
#define glVertexAttribI1uiv ffw::gl::glVertexAttribI1uiv
#define glVertexAttribI2i ffw::gl::glVertexAttribI2i
#define glVertexAttribI2iv ffw::gl::glVertexAttribI2iv
#define glVertexAttribI2ui ffw::gl::glVertexAttribI2ui
#define glVertexAttribI2uiv ffw::gl::glVertexAttribI2uiv
#define glVertexAttribI3i ffw::gl::glVertexAttribI3i
#define glVertexAttribI3iv ffw::gl::glVertexAttribI3iv
#define glVertexAttribI3ui ffw::gl::glVertexAttribI3ui
#define glVertexAttribI3uiv ffw::gl::glVertexAttribI3uiv
#define glVertexAttribI4bv ffw::gl::glVertexAttribI4bv
#define glVertexAttribI4i ffw::gl::glVertexAttribI4i
#define glVertexAttribI4iv ffw::gl::glVertexAttribI4iv
#define glVertexAttribI4sv ffw::gl::glVertexAttribI4sv
#define glVertexAttribI4ubv ffw::gl::glVertexAttribI4ubv
#define glVertexAttribI4ui ffw::gl::glVertexAttribI4ui
#define glVertexAttribI4uiv ffw::gl::glVertexAttribI4uiv
#define glVertexAttribI4usv ffw::gl::glVertexAttribI4usv
#define glVertexAttribIPointer ffw::gl::glVertexAttribIPointer
#endif /* GL_VERSION_3_0 */

#ifdef GL_VERSION_3_1
#define glCopyBufferSubData ffw::gl::glCopyBufferSubData
#define glDrawArraysInstanced ffw::gl::glDrawArraysInstanced
#define glDrawElementsInstanced ffw::gl::glDrawElementsInstanced
#define glGetActiveUniformBlockiv ffw::gl::glGetActiveUniformBlockiv
#define glGetActiveUniformBlockName ffw::gl::glGetActiveUniformBlockName
#define glGetActiveUniformName ffw::gl::glGetActiveUniformName
#define glGetActiveUniformsiv ffw::gl::glGetActiveUniformsiv
#define glGetUniformBlockIndex ffw::gl::glGetUniformBlockIndex
#define glGetUniformIndices ffw::gl::glGetUniformIndices
#define glPrimitiveRestartIndex ffw::gl::glPrimitiveRestartIndex
#define glTexBuffer ffw::gl::glTexBuffer
#define glUniformBlockBinding ffw::gl::glUniformBlockBinding
#endif /* GL_VERSION_3_1 */

#ifdef GL_VERSION_3_2
#define glClientWaitSync ffw::gl::glClientWaitSync
#define glDeleteSync ffw::gl::glDeleteSync
#define glDrawElementsBaseVertex ffw::gl::glDrawElementsBaseVertex
#define glDrawElementsInstancedBaseVertex ffw::gl::glDrawElementsInstancedBaseVertex
#define glDrawRangeElementsBaseVertex ffw::gl::glDrawRangeElementsBaseVertex
#define glFenceSync ffw::gl::glFenceSync
#define glFramebufferTexture ffw::gl::glFramebufferTexture
#define glGetBufferParameteri64v ffw::gl::glGetBufferParameteri64v
#define glGetInteger64i_v ffw::gl::glGetInteger64i_v
#define glGetInteger64v ffw::gl::glGetInteger64v
#define glGetMultisamplefv ffw::gl::glGetMultisamplefv
#define glGetSynciv ffw::gl::glGetSynciv
#define glIsSync ffw::gl::glIsSync
#define glMultiDrawElementsBaseVertex ffw::gl::glMultiDrawElementsBaseVertex
#define glProvokingVertex ffw::gl::glProvokingVertex
#define glSampleMaski ffw::gl::glSampleMaski
#define glTexImage2DMultisample ffw::gl::glTexImage2DMultisample
#define glTexImage3DMultisample ffw::gl::glTexImage3DMultisample
#define glWaitSync ffw::gl::glWaitSync
#endif /* GL_VERSION_3_2 */

#ifdef GL_VERSION_3_3
#define glBindFragDataLocationIndexed ffw::gl::glBindFragDataLocationIndexed
#define glBindSampler ffw::gl::glBindSampler
#define glDeleteSamplers ffw::gl::glDeleteSamplers
#define glGenSamplers ffw::gl::glGenSamplers
#define glGetFragDataIndex ffw::gl::glGetFragDataIndex
#define glGetQueryObjecti64v ffw::gl::glGetQueryObjecti64v
#define glGetQueryObjectui64v ffw::gl::glGetQueryObjectui64v
#define glGetSamplerParameterfv ffw::gl::glGetSamplerParameterfv
#define glGetSamplerParameterIiv ffw::gl::glGetSamplerParameterIiv
#define glGetSamplerParameterIuiv ffw::gl::glGetSamplerParameterIuiv
#define glGetSamplerParameteriv ffw::gl::glGetSamplerParameteriv
#define glIsSampler ffw::gl::glIsSampler
#define glQueryCounter ffw::gl::glQueryCounter
#define glSamplerParameterf ffw::gl::glSamplerParameterf
#define glSamplerParameterfv ffw::gl::glSamplerParameterfv
#define glSamplerParameterIiv ffw::gl::glSamplerParameterIiv
#define glSamplerParameteri ffw::gl::glSamplerParameteri
#define glSamplerParameterIuiv ffw::gl::glSamplerParameterIuiv
#define glSamplerParameteriv ffw::gl::glSamplerParameteriv
#define glVertexAttribDivisor ffw::gl::glVertexAttribDivisor
#define glVertexAttribP1ui ffw::gl::glVertexAttribP1ui
#define glVertexAttribP1uiv ffw::gl::glVertexAttribP1uiv
#define glVertexAttribP2ui ffw::gl::glVertexAttribP2ui
#define glVertexAttribP2uiv ffw::gl::glVertexAttribP2uiv
#define glVertexAttribP3ui ffw::gl::glVertexAttribP3ui
#define glVertexAttribP3uiv ffw::gl::glVertexAttribP3uiv
#define glVertexAttribP4ui ffw::gl::glVertexAttribP4ui
#define glVertexAttribP4uiv ffw::gl::glVertexAttribP4uiv
#endif /* GL_VERSION_3_3 */

#ifdef GL_VERSION_4_0
#define glBeginQueryIndexed ffw::gl::glBeginQueryIndexed
#define glBindTransformFeedback ffw::gl::glBindTransformFeedback
#define glBlendEquationi ffw::gl::glBlendEquationi
#define glBlendEquationSeparatei ffw::gl::glBlendEquationSeparatei
#define glBlendFunci ffw::gl::glBlendFunci
#define glBlendFuncSeparatei ffw::gl::glBlendFuncSeparatei
#define glDeleteTransformFeedbacks ffw::gl::glDeleteTransformFeedbacks
#define glDrawArraysIndirect ffw::gl::glDrawArraysIndirect
#define glDrawElementsIndirect ffw::gl::glDrawElementsIndirect
#define glDrawTransformFeedback ffw::gl::glDrawTransformFeedback
#define glDrawTransformFeedbackStream ffw::gl::glDrawTransformFeedbackStream
#define glEndQueryIndexed ffw::gl::glEndQueryIndexed
#define glGenTransformFeedbacks ffw::gl::glGenTransformFeedbacks
#define glGetActiveSubroutineName ffw::gl::glGetActiveSubroutineName
#define glGetActiveSubroutineUniformiv ffw::gl::glGetActiveSubroutineUniformiv
#define glGetActiveSubroutineUniformName ffw::gl::glGetActiveSubroutineUniformName
#define glGetProgramStageiv ffw::gl::glGetProgramStageiv
#define glGetQueryIndexediv ffw::gl::glGetQueryIndexediv
#define glGetSubroutineIndex ffw::gl::glGetSubroutineIndex
#define glGetSubroutineUniformLocation ffw::gl::glGetSubroutineUniformLocation
#define glGetUniformdv ffw::gl::glGetUniformdv
#define glGetUniformSubroutineuiv ffw::gl::glGetUniformSubroutineuiv
#define glIsTransformFeedback ffw::gl::glIsTransformFeedback
#define glMinSampleShading ffw::gl::glMinSampleShading
#define glPatchParameterfv ffw::gl::glPatchParameterfv
#define glPatchParameteri ffw::gl::glPatchParameteri
#define glPauseTransformFeedback ffw::gl::glPauseTransformFeedback
#define glResumeTransformFeedback ffw::gl::glResumeTransformFeedback
#define glUniform1d ffw::gl::glUniform1d
#define glUniform1dv ffw::gl::glUniform1dv
#define glUniform2d ffw::gl::glUniform2d
#define glUniform2dv ffw::gl::glUniform2dv
#define glUniform3d ffw::gl::glUniform3d
#define glUniform3dv ffw::gl::glUniform3dv
#define glUniform4d ffw::gl::glUniform4d
#define glUniform4dv ffw::gl::glUniform4dv
#define glUniformMatrix2dv ffw::gl::glUniformMatrix2dv
#define glUniformMatrix2x3dv ffw::gl::glUniformMatrix2x3dv
#define glUniformMatrix2x4dv ffw::gl::glUniformMatrix2x4dv
#define glUniformMatrix3dv ffw::gl::glUniformMatrix3dv
#define glUniformMatrix3x2dv ffw::gl::glUniformMatrix3x2dv
#define glUniformMatrix3x4dv ffw::gl::glUniformMatrix3x4dv
#define glUniformMatrix4dv ffw::gl::glUniformMatrix4dv
#define glUniformMatrix4x2dv ffw::gl::glUniformMatrix4x2dv
#define glUniformMatrix4x3dv ffw::gl::glUniformMatrix4x3dv
#define glUniformSubroutinesuiv ffw::gl::glUniformSubroutinesuiv
#endif /* GL_VERSION_4_0 */

#ifdef GL_VERSION_4_1
#define glActiveShaderProgram ffw::gl::glActiveShaderProgram
#define glBindProgramPipeline ffw::gl::glBindProgramPipeline
#define glClearDepthf ffw::gl::glClearDepthf
#define glCreateShaderProgramv ffw::gl::glCreateShaderProgramv
#define glDeleteProgramPipelines ffw::gl::glDeleteProgramPipelines
#define glDepthRangeArrayv ffw::gl::glDepthRangeArrayv
#define glDepthRangef ffw::gl::glDepthRangef
#define glDepthRangeIndexed ffw::gl::glDepthRangeIndexed
#define glGenProgramPipelines ffw::gl::glGenProgramPipelines
#define glGetDoublei_v ffw::gl::glGetDoublei_v
#define glGetFloati_v ffw::gl::glGetFloati_v
#define glGetProgramBinary ffw::gl::glGetProgramBinary
#define glGetProgramPipelineInfoLog ffw::gl::glGetProgramPipelineInfoLog
#define glGetProgramPipelineiv ffw::gl::glGetProgramPipelineiv
#define glGetShaderPrecisionFormat ffw::gl::glGetShaderPrecisionFormat
#define glGetVertexAttribLdv ffw::gl::glGetVertexAttribLdv
#define glIsProgramPipeline ffw::gl::glIsProgramPipeline
#define glProgramBinary ffw::gl::glProgramBinary
#define glProgramParameteri ffw::gl::glProgramParameteri
#define glProgramUniform1d ffw::gl::glProgramUniform1d
#define glProgramUniform1dv ffw::gl::glProgramUniform1dv
#define glProgramUniform1f ffw::gl::glProgramUniform1f
#define glProgramUniform1fv ffw::gl::glProgramUniform1fv
#define glProgramUniform1i ffw::gl::glProgramUniform1i
#define glProgramUniform1iv ffw::gl::glProgramUniform1iv
#define glProgramUniform1ui ffw::gl::glProgramUniform1ui
#define glProgramUniform1uiv ffw::gl::glProgramUniform1uiv
#define glProgramUniform2d ffw::gl::glProgramUniform2d
#define glProgramUniform2dv ffw::gl::glProgramUniform2dv
#define glProgramUniform2f ffw::gl::glProgramUniform2f
#define glProgramUniform2fv ffw::gl::glProgramUniform2fv
#define glProgramUniform2i ffw::gl::glProgramUniform2i
#define glProgramUniform2iv ffw::gl::glProgramUniform2iv
#define glProgramUniform2ui ffw::gl::glProgramUniform2ui
#define glProgramUniform2uiv ffw::gl::glProgramUniform2uiv
#define glProgramUniform3d ffw::gl::glProgramUniform3d
#define glProgramUniform3dv ffw::gl::glProgramUniform3dv
#define glProgramUniform3f ffw::gl::glProgramUniform3f
#define glProgramUniform3fv ffw::gl::glProgramUniform3fv
#define glProgramUniform3i ffw::gl::glProgramUniform3i
#define glProgramUniform3iv ffw::gl::glProgramUniform3iv
#define glProgramUniform3ui ffw::gl::glProgramUniform3ui
#define glProgramUniform3uiv ffw::gl::glProgramUniform3uiv
#define glProgramUniform4d ffw::gl::glProgramUniform4d
#define glProgramUniform4dv ffw::gl::glProgramUniform4dv
#define glProgramUniform4f ffw::gl::glProgramUniform4f
#define glProgramUniform4fv ffw::gl::glProgramUniform4fv
#define glProgramUniform4i ffw::gl::glProgramUniform4i
#define glProgramUniform4iv ffw::gl::glProgramUniform4iv
#define glProgramUniform4ui ffw::gl::glProgramUniform4ui
#define glProgramUniform4uiv ffw::gl::glProgramUniform4uiv
#define glProgramUniformMatrix2dv ffw::gl::glProgramUniformMatrix2dv
#define glProgramUniformMatrix2fv ffw::gl::glProgramUniformMatrix2fv
#define glProgramUniformMatrix2x3dv ffw::gl::glProgramUniformMatrix2x3dv
#define glProgramUniformMatrix2x3fv ffw::gl::glProgramUniformMatrix2x3fv
#define glProgramUniformMatrix2x4dv ffw::gl::glProgramUniformMatrix2x4dv
#define glProgramUniformMatrix2x4fv ffw::gl::glProgramUniformMatrix2x4fv
#define glProgramUniformMatrix3dv ffw::gl::glProgramUniformMatrix3dv
#define glProgramUniformMatrix3fv ffw::gl::glProgramUniformMatrix3fv
#define glProgramUniformMatrix3x2dv ffw::gl::glProgramUniformMatrix3x2dv
#define glProgramUniformMatrix3x2fv ffw::gl::glProgramUniformMatrix3x2fv
#define glProgramUniformMatrix3x4dv ffw::gl::glProgramUniformMatrix3x4dv
#define glProgramUniformMatrix3x4fv ffw::gl::glProgramUniformMatrix3x4fv
#define glProgramUniformMatrix4dv ffw::gl::glProgramUniformMatrix4dv
#define glProgramUniformMatrix4fv ffw::gl::glProgramUniformMatrix4fv
#define glProgramUniformMatrix4x2dv ffw::gl::glProgramUniformMatrix4x2dv
#define glProgramUniformMatrix4x2fv ffw::gl::glProgramUniformMatrix4x2fv
#define glProgramUniformMatrix4x3dv ffw::gl::glProgramUniformMatrix4x3dv
#define glProgramUniformMatrix4x3fv ffw::gl::glProgramUniformMatrix4x3fv
#define glReleaseShaderCompiler ffw::gl::glReleaseShaderCompiler
#define glScissorArrayv ffw::gl::glScissorArrayv
#define glScissorIndexed ffw::gl::glScissorIndexed
#define glScissorIndexedv ffw::gl::glScissorIndexedv
#define glShaderBinary ffw::gl::glShaderBinary
#define glUseProgramStages ffw::gl::glUseProgramStages
#define glValidateProgramPipeline ffw::gl::glValidateProgramPipeline
#define glVertexAttribL1d ffw::gl::glVertexAttribL1d
#define glVertexAttribL1dv ffw::gl::glVertexAttribL1dv
#define glVertexAttribL2d ffw::gl::glVertexAttribL2d
#define glVertexAttribL2dv ffw::gl::glVertexAttribL2dv
#define glVertexAttribL3d ffw::gl::glVertexAttribL3d
#define glVertexAttribL3dv ffw::gl::glVertexAttribL3dv
#define glVertexAttribL4d ffw::gl::glVertexAttribL4d
#define glVertexAttribL4dv ffw::gl::glVertexAttribL4dv
#define glVertexAttribLPointer ffw::gl::glVertexAttribLPointer
#define glViewportArrayv ffw::gl::glViewportArrayv
#define glViewportIndexedf ffw::gl::glViewportIndexedf
#define glViewportIndexedfv ffw::gl::glViewportIndexedfv
#endif /* GL_VERSION_4_1 */

#ifdef GL_VERSION_4_2
#define glBindImageTexture ffw::gl::glBindImageTexture
#define glDrawArraysInstancedBaseInstance ffw::gl::glDrawArraysInstancedBaseInstance
#define glDrawElementsInstancedBaseInstance ffw::gl::glDrawElementsInstancedBaseInstance
#define glDrawElementsInstancedBaseVertexBaseInstance ffw::gl::glDrawElementsInstancedBaseVertexBaseInstance
#define glDrawTransformFeedbackInstanced ffw::gl::glDrawTransformFeedbackInstanced
#define glDrawTransformFeedbackStreamInstanced ffw::gl::glDrawTransformFeedbackStreamInstanced
#define glGetActiveAtomicCounterBufferiv ffw::gl::glGetActiveAtomicCounterBufferiv
#define glGetInternalformativ ffw::gl::glGetInternalformativ
#define glMemoryBarrier ffw::gl::glMemoryBarrier
#define glTexStorage1D ffw::gl::glTexStorage1D
#define glTexStorage2D ffw::gl::glTexStorage2D
#define glTexStorage3D ffw::gl::glTexStorage3D
#endif /* GL_VERSION_4_2 */

#ifdef GL_VERSION_4_3
#define glBindVertexBuffer ffw::gl::glBindVertexBuffer
#define glClearBufferData ffw::gl::glClearBufferData
#define glClearBufferSubData ffw::gl::glClearBufferSubData
#define glCopyImageSubData ffw::gl::glCopyImageSubData
#define glDebugMessageCallback ffw::gl::glDebugMessageCallback
#define glDebugMessageControl ffw::gl::glDebugMessageControl
#define glDebugMessageInsert ffw::gl::glDebugMessageInsert
#define glDispatchComputeIndirect ffw::gl::glDispatchComputeIndirect
#define glDispatchCompute ffw::gl::glDispatchCompute
#define glFramebufferParameteri ffw::gl::glFramebufferParameteri
#define glGetDebugMessageLog ffw::gl::glGetDebugMessageLog
#define glGetFramebufferParameteriv ffw::gl::glGetFramebufferParameteriv
#define glGetInternalformati64v ffw::gl::glGetInternalformati64v
#define glGetObjectLabel ffw::gl::glGetObjectLabel
#define glGetObjectPtrLabel ffw::gl::glGetObjectPtrLabel
#define glGetProgramInterfaceiv ffw::gl::glGetProgramInterfaceiv
#define glGetProgramResourceIndex ffw::gl::glGetProgramResourceIndex
#define glGetProgramResourceiv ffw::gl::glGetProgramResourceiv
#define glGetProgramResourceLocationIndex ffw::gl::glGetProgramResourceLocationIndex
#define glGetProgramResourceLocation ffw::gl::glGetProgramResourceLocation
#define glGetProgramResourceName ffw::gl::glGetProgramResourceName
#define glInvalidateBufferData ffw::gl::glInvalidateBufferData
#define glInvalidateBufferSubData ffw::gl::glInvalidateBufferSubData
#define glInvalidateFramebuffer ffw::gl::glInvalidateFramebuffer
#define glInvalidateSubFramebuffer ffw::gl::glInvalidateSubFramebuffer
#define glInvalidateTexImage ffw::gl::glInvalidateTexImage
#define glInvalidateTexSubImage ffw::gl::glInvalidateTexSubImage
#define glMultiDrawArraysIndirect ffw::gl::glMultiDrawArraysIndirect
#define glMultiDrawElementsIndirect ffw::gl::glMultiDrawElementsIndirect
#define glObjectLabel ffw::gl::glObjectLabel
#define glObjectPtrLabel ffw::gl::glObjectPtrLabel
#define glPopDebugGroup ffw::gl::glPopDebugGroup
#define glPushDebugGroup ffw::gl::glPushDebugGroup
#define glShaderStorageBlockBinding ffw::gl::glShaderStorageBlockBinding
#define glTexBufferRange ffw::gl::glTexBufferRange
#define glTexStorage2DMultisample ffw::gl::glTexStorage2DMultisample
#define glTexStorage3DMultisample ffw::gl::glTexStorage3DMultisample
#define glTextureView ffw::gl::glTextureView
#define glVertexAttribBinding ffw::gl::glVertexAttribBinding
#define glVertexAttribFormat ffw::gl::glVertexAttribFormat
#define glVertexAttribIFormat ffw::gl::glVertexAttribIFormat
#define glVertexAttribLFormat ffw::gl::glVertexAttribLFormat
#define glVertexBindingDivisor ffw::gl::glVertexBindingDivisor
#endif /* GL_VERSION_4_3 */

#ifdef GL_VERSION_4_4
#define glBindBuffersBase ffw::gl::glBindBuffersBase
#define glBindBuffersRange ffw::gl::glBindBuffersRange
#define glBindImageTextures ffw::gl::glBindImageTextures
#define glBindSamplers ffw::gl::glBindSamplers
#define glBindTextures ffw::gl::glBindTextures
#define glBindVertexBuffers ffw::gl::glBindVertexBuffers
#define glBufferStorage ffw::gl::glBufferStorage
#define glClearTexImage ffw::gl::glClearTexImage
#define glClearTexSubImage ffw::gl::glClearTexSubImage
#endif /* GL_VERSION_4_4 */

#ifdef GL_VERSION_4_5
#define glBindTextureUnit ffw::gl::glBindTextureUnit
#define glBlitNamedFramebuffer ffw::gl::glBlitNamedFramebuffer
#define glCheckNamedFramebufferStatus ffw::gl::glCheckNamedFramebufferStatus
#define glClearNamedBufferData ffw::gl::glClearNamedBufferData
#define glClearNamedBufferSubData ffw::gl::glClearNamedBufferSubData
#define glClearNamedFramebufferfi ffw::gl::glClearNamedFramebufferfi
#define glClearNamedFramebufferfv ffw::gl::glClearNamedFramebufferfv
#define glClearNamedFramebufferiv ffw::gl::glClearNamedFramebufferiv
#define glClearNamedFramebufferuiv ffw::gl::glClearNamedFramebufferuiv
#define glClipControl ffw::gl::glClipControl
#define glCompressedTextureSubImage1D ffw::gl::glCompressedTextureSubImage1D
#define glCompressedTextureSubImage2D ffw::gl::glCompressedTextureSubImage2D
#define glCompressedTextureSubImage3D ffw::gl::glCompressedTextureSubImage3D
#define glCopyNamedBufferSubData ffw::gl::glCopyNamedBufferSubData
#define glCopyTextureSubImage1D ffw::gl::glCopyTextureSubImage1D
#define glCopyTextureSubImage2D ffw::gl::glCopyTextureSubImage2D
#define glCopyTextureSubImage3D ffw::gl::glCopyTextureSubImage3D
#define glCreateBuffers ffw::gl::glCreateBuffers
#define glCreateFramebuffers ffw::gl::glCreateFramebuffers
#define glCreateProgramPipelines ffw::gl::glCreateProgramPipelines
#define glCreateQueries ffw::gl::glCreateQueries
#define glCreateRenderbuffers ffw::gl::glCreateRenderbuffers
#define glCreateSamplers ffw::gl::glCreateSamplers
#define glCreateTextures ffw::gl::glCreateTextures
#define glCreateTransformFeedbacks ffw::gl::glCreateTransformFeedbacks
#define glCreateVertexArrays ffw::gl::glCreateVertexArrays
#define glDisableVertexArrayAttrib ffw::gl::glDisableVertexArrayAttrib
#define glEnableVertexArrayAttrib ffw::gl::glEnableVertexArrayAttrib
#define glFlushMappedNamedBufferRange ffw::gl::glFlushMappedNamedBufferRange
#define glGenerateTextureMipmap ffw::gl::glGenerateTextureMipmap
#define glGetCompressedTextureImage ffw::gl::glGetCompressedTextureImage
#define glGetCompressedTextureSubImage ffw::gl::glGetCompressedTextureSubImage
#define glGetGraphicsResetStatus ffw::gl::glGetGraphicsResetStatus
#define glGetNamedBufferParameteri64v ffw::gl::glGetNamedBufferParameteri64v
#define glGetNamedBufferParameteriv ffw::gl::glGetNamedBufferParameteriv
#define glGetNamedBufferPointerv ffw::gl::glGetNamedBufferPointerv
#define glGetNamedBufferSubData ffw::gl::glGetNamedBufferSubData
#define glGetNamedFramebufferAttachmentParameteriv ffw::gl::glGetNamedFramebufferAttachmentParameteriv
#define glGetNamedFramebufferParameteriv ffw::gl::glGetNamedFramebufferParameteriv
#define glGetNamedRenderbufferParameteriv ffw::gl::glGetNamedRenderbufferParameteriv
#define glGetnCompressedTexImage ffw::gl::glGetnCompressedTexImage
#define glGetnTexImage ffw::gl::glGetnTexImage
#define glGetnUniformdv ffw::gl::glGetnUniformdv
#define glGetnUniformfv ffw::gl::glGetnUniformfv
#define glGetnUniformiv ffw::gl::glGetnUniformiv
#define glGetnUniformuiv ffw::gl::glGetnUniformuiv
#define glGetQueryBufferObjecti64v ffw::gl::glGetQueryBufferObjecti64v
#define glGetQueryBufferObjectiv ffw::gl::glGetQueryBufferObjectiv
#define glGetQueryBufferObjectui64v ffw::gl::glGetQueryBufferObjectui64v
#define glGetQueryBufferObjectuiv ffw::gl::glGetQueryBufferObjectuiv
#define glGetTextureImage ffw::gl::glGetTextureImage
#define glGetTextureLevelParameterfv ffw::gl::glGetTextureLevelParameterfv
#define glGetTextureLevelParameteriv ffw::gl::glGetTextureLevelParameteriv
#define glGetTextureParameterfv ffw::gl::glGetTextureParameterfv
#define glGetTextureParameterIiv ffw::gl::glGetTextureParameterIiv
#define glGetTextureParameterIuiv ffw::gl::glGetTextureParameterIuiv
#define glGetTextureParameteriv ffw::gl::glGetTextureParameteriv
#define glGetTextureSubImage ffw::gl::glGetTextureSubImage
#define glGetTransformFeedbacki64_v ffw::gl::glGetTransformFeedbacki64_v
#define glGetTransformFeedbackiv ffw::gl::glGetTransformFeedbackiv
#define glGetTransformFeedbacki_v ffw::gl::glGetTransformFeedbacki_v
#define glGetVertexArrayIndexed64iv ffw::gl::glGetVertexArrayIndexed64iv
#define glGetVertexArrayIndexediv ffw::gl::glGetVertexArrayIndexediv
#define glGetVertexArrayiv ffw::gl::glGetVertexArrayiv
#define glInvalidateNamedFramebufferData ffw::gl::glInvalidateNamedFramebufferData
#define glInvalidateNamedFramebufferSubData ffw::gl::glInvalidateNamedFramebufferSubData
#define glMapNamedBuffer ffw::gl::glMapNamedBuffer
#define glMapNamedBufferRange ffw::gl::glMapNamedBufferRange
#define glMemoryBarrierByRegion ffw::gl::glMemoryBarrierByRegion
#define glNamedBufferData ffw::gl::glNamedBufferData
#define glNamedBufferStorage ffw::gl::glNamedBufferStorage
#define glNamedBufferSubData ffw::gl::glNamedBufferSubData
#define glNamedFramebufferDrawBuffer ffw::gl::glNamedFramebufferDrawBuffer
#define glNamedFramebufferDrawBuffers ffw::gl::glNamedFramebufferDrawBuffers
#define glNamedFramebufferParameteri ffw::gl::glNamedFramebufferParameteri
#define glNamedFramebufferReadBuffer ffw::gl::glNamedFramebufferReadBuffer
#define glNamedFramebufferRenderbuffer ffw::gl::glNamedFramebufferRenderbuffer
#define glNamedFramebufferTextureLayer ffw::gl::glNamedFramebufferTextureLayer
#define glNamedFramebufferTexture ffw::gl::glNamedFramebufferTexture
#define glNamedRenderbufferStorageMultisample ffw::gl::glNamedRenderbufferStorageMultisample
#define glNamedRenderbufferStorage ffw::gl::glNamedRenderbufferStorage
#define glReadnPixels ffw::gl::glReadnPixels
#define glTextureBarrier ffw::gl::glTextureBarrier
#define glTextureBuffer ffw::gl::glTextureBuffer
#define glTextureBufferRange ffw::gl::glTextureBufferRange
#define glTextureParameterf ffw::gl::glTextureParameterf
#define glTextureParameterfv ffw::gl::glTextureParameterfv
#define glTextureParameterIiv ffw::gl::glTextureParameterIiv
#define glTextureParameteri ffw::gl::glTextureParameteri
#define glTextureParameterIuiv ffw::gl::glTextureParameterIuiv
#define glTextureParameteriv ffw::gl::glTextureParameteriv
#define glTextureStorage1D ffw::gl::glTextureStorage1D
#define glTextureStorage2DMultisample ffw::gl::glTextureStorage2DMultisample
#define glTextureStorage2D ffw::gl::glTextureStorage2D
#define glTextureStorage3DMultisample ffw::gl::glTextureStorage3DMultisample
#define glTextureStorage3D ffw::gl::glTextureStorage3D
#define glTextureSubImage1D ffw::gl::glTextureSubImage1D
#define glTextureSubImage2D ffw::gl::glTextureSubImage2D
#define glTextureSubImage3D ffw::gl::glTextureSubImage3D
#define glTransformFeedbackBufferBase ffw::gl::glTransformFeedbackBufferBase
#define glTransformFeedbackBufferRange ffw::gl::glTransformFeedbackBufferRange
#define glUnmapNamedBuffer ffw::gl::glUnmapNamedBuffer
#define glVertexArrayAttribBinding ffw::gl::glVertexArrayAttribBinding
#define glVertexArrayAttribFormat ffw::gl::glVertexArrayAttribFormat
#define glVertexArrayAttribIFormat ffw::gl::glVertexArrayAttribIFormat
#define glVertexArrayAttribLFormat ffw::gl::glVertexArrayAttribLFormat
#define glVertexArrayBindingDivisor ffw::gl::glVertexArrayBindingDivisor
#define glVertexArrayElementBuffer ffw::gl::glVertexArrayElementBuffer
#define glVertexArrayVertexBuffer ffw::gl::glVertexArrayVertexBuffer
#define glVertexArrayVertexBuffers ffw::gl::glVertexArrayVertexBuffers
#endif /* GL_VERSION_4_5 */

#ifdef GL_VERSION_4_6
#define glMultiDrawArraysIndirectCount ffw::gl::glMultiDrawArraysIndirectCount
#define glMultiDrawElementsIndirectCount ffw::gl::glMultiDrawElementsIndirectCount
#define glPolygonOffsetClamp ffw::gl::glPolygonOffsetClamp
#define glSpecializeShader ffw::gl::glSpecializeShader
#endif /* GL_VERSION_4_6 */
#endif

#endif
```


    
  
