//
// Compatibility header for older version of SDL.
// Include this instead of SDL.h directly.
//

#pragma once

#include <SDL.h>
#include <stdbool.h>

// This is a pure C header for compatibility with SDL.h
#ifdef __cplusplus
extern "C" {
#endif

// SDL_FRect wasn't added until 2.0.10
#if !SDL_VERSION_ATLEAST(2, 0, 10)
typedef struct SDL_FRect
{
    float x;
    float y;
    float w;
    float h;
} SDL_FRect;
#endif

#ifndef SDL_HINT_VIDEO_X11_FORCE_EGL
#define SDL_HINT_VIDEO_X11_FORCE_EGL "SDL_VIDEO_X11_FORCE_EGL"
#endif

#ifndef SDL_HINT_KMSDRM_REQUIRE_DRM_MASTER
#define SDL_HINT_KMSDRM_REQUIRE_DRM_MASTER "SDL_KMSDRM_REQUIRE_DRM_MASTER"
#endif

#ifndef SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED
#define SDL_HINT_ALLOW_ALT_TAB_WHILE_GRABBED "SDL_ALLOW_ALT_TAB_WHILE_GRABBED"
#endif

#ifndef SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE
#define SDL_HINT_JOYSTICK_HIDAPI_PS4_RUMBLE "SDL_JOYSTICK_HIDAPI_PS4_RUMBLE"
#endif

#ifndef SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE
#define SDL_HINT_JOYSTICK_HIDAPI_PS5_RUMBLE "SDL_JOYSTICK_HIDAPI_PS5_RUMBLE"
#endif

#ifndef SDL_HINT_WINDOWS_USE_D3D9EX
#define SDL_HINT_WINDOWS_USE_D3D9EX "SDL_WINDOWS_USE_D3D9EX"
#endif

#ifndef SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS
#define SDL_HINT_GAMECONTROLLER_USE_BUTTON_LABELS "SDL_GAMECONTROLLER_USE_BUTTON_LABELS"
#endif

#ifndef SDL_HINT_MOUSE_RELATIVE_SCALING
#define SDL_HINT_MOUSE_RELATIVE_SCALING "SDL_MOUSE_RELATIVE_SCALING"
#endif

#ifndef SDL_HINT_AUDIO_DEVICE_APP_NAME
#define SDL_HINT_AUDIO_DEVICE_APP_NAME "SDL_AUDIO_DEVICE_APP_NAME"
#endif

#ifndef SDL_HINT_APP_NAME
#define SDL_HINT_APP_NAME "SDL_APP_NAME"
#endif

#ifndef SDL_HINT_MOUSE_AUTO_CAPTURE
#define SDL_HINT_MOUSE_AUTO_CAPTURE "SDL_MOUSE_AUTO_CAPTURE"
#endif

#ifndef SDL_HINT_VIDEO_WAYLAND_EMULATE_MOUSE_WARP
#define SDL_HINT_VIDEO_WAYLAND_EMULATE_MOUSE_WARP "SDL_VIDEO_WAYLAND_EMULATE_MOUSE_WARP"
#endif

void* SDLC_Win32_GetHwnd(SDL_Window* window);
void* SDLC_MacOS_GetWindow(SDL_Window* window);
void* SDLC_X11_GetDisplay(SDL_Window* window);
unsigned long SDLC_X11_GetWindow(SDL_Window* window);
void* SDLC_Wayland_GetDisplay(SDL_Window* window);
void* SDLC_Wayland_GetSurface(SDL_Window* window);
int SDLC_KMSDRM_GetFd(SDL_Window* window);
int SDLC_KMSDRM_GetDevIndex(SDL_Window* window);

typedef enum {
    SDLC_VIDEO_UNKNOWN,
    SDLC_VIDEO_WIN32,
    SDLC_VIDEO_MACOS,
    SDLC_VIDEO_X11,
    SDLC_VIDEO_WAYLAND,
    SDLC_VIDEO_KMSDRM,
} SDLC_VideoDriver;
SDLC_VideoDriver SDLC_GetVideoDriver();

bool SDLC_IsFullscreen(SDL_Window* window);
bool SDLC_IsFullscreenExclusive(SDL_Window* window);
bool SDLC_IsFullscreenDesktop(SDL_Window* window);
void SDLC_EnterFullscreen(SDL_Window* window, bool exclusive);
void SDLC_LeaveFullscreen(SDL_Window* window);

SDL_Window* SDLC_CreateWindowWithFallback(const char *title,
                                          int x, int y, int w, int h,
                                          Uint32 requiredFlags,
                                          Uint32 optionalFlags);

void SDLC_FlushWindowEvents();

#ifdef __cplusplus
}
#endif
