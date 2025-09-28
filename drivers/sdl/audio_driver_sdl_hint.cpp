/**************************************************************************/
/*  audio_driver_sdl_hint.cpp                                             */
/**************************************************************************/
/*                         This file is part of:                          */
/*                             GODOT ENGINE                               */
/*                        https://godotengine.org                         */
/**************************************************************************/
/* Copyright (c) 2014-present Godot Engine contributors (see AUTHORS.md). */
/* Copyright (c) 2007-2014 Juan Linietsky, Ariel Manzur.                  */
/*                                                                        */
/* Permission is hereby granted, free of charge, to any person obtaining  */
/* a copy of this software and associated documentation files (the        */
/* "Software"), to deal in the Software without restriction, including    */
/* without limitation the rights to use, copy, modify, merge, publish,    */
/* distribute, sublicense, and/or sell copies of the Software, and to     */
/* permit persons to whom the Software is furnished to do so, subject to  */
/* the following conditions:                                              */
/*                                                                        */
/* The above copyright notice and this permission notice shall be         */
/* included in all copies or substantial portions of the Software.        */
/*                                                                        */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,        */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF     */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. */
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY   */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,   */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE      */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                 */
/**************************************************************************/

#include "audio_driver_sdl_hint.h"

#include "drivers/sdl/audio_driver_sdl.h"

#include <SDL3/SDL_hints.h>

bool AudioDriverSDLNone::failed_to_init = false;

Error AudioDriverSDLHint::init() {
	SDL_SetHintWithPriority(SDL_HINT_AUDIO_DRIVER, get_driver_name(), SDL_HINT_OVERRIDE);
	Error err = AudioDriverSDL::get_singleton()->init();
	if (unlikely(err != OK)) {
		SDL_ResetHint(SDL_HINT_AUDIO_DRIVER);
		return err;
	}
	return OK;
}

void AudioDriverSDLHint::start() {
	return AudioDriverSDL::get_singleton()->start();
}

int AudioDriverSDLHint::get_mix_rate() const {
	return AudioDriverSDL::get_singleton()->get_mix_rate();
}

AudioDriver::SpeakerMode AudioDriverSDLHint::get_speaker_mode() const {
	return AudioDriverSDL::get_singleton()->get_speaker_mode();
}

float AudioDriverSDLHint::get_latency() {
	return AudioDriverSDL::get_singleton()->get_latency();
}

void AudioDriverSDLHint::lock() {
	return AudioDriverSDL::get_singleton()->lock();
}

void AudioDriverSDLHint::unlock() {
	return AudioDriverSDL::get_singleton()->unlock();
}

void AudioDriverSDLHint::finish() {
	return AudioDriverSDL::get_singleton()->finish();
}

PackedStringArray AudioDriverSDLHint::get_output_device_list() {
	return AudioDriverSDL::get_singleton()->get_output_device_list();
}

String AudioDriverSDLHint::get_output_device() {
	return AudioDriverSDL::get_singleton()->get_output_device();
}

void AudioDriverSDLHint::set_output_device(const String &p_name) {
	return AudioDriverSDL::get_singleton()->set_output_device(p_name);
}

Error AudioDriverSDLHint::input_start() {
	return AudioDriverSDL::get_singleton()->input_start();
}

Error AudioDriverSDLHint::input_stop() {
	return AudioDriverSDL::get_singleton()->input_stop();
}

PackedStringArray AudioDriverSDLHint::get_input_device_list() {
	return AudioDriverSDL::get_singleton()->get_input_device_list();
}

String AudioDriverSDLHint::get_input_device() {
	return AudioDriverSDL::get_singleton()->get_input_device();
}

void AudioDriverSDLHint::set_input_device(const String &p_name) {
	return AudioDriverSDL::get_singleton()->set_input_device(p_name);
}

Error AudioDriverSDLNone::init() {
	Error err = AudioDriverSDLHint::init();
	if (unlikely(err != OK)) {
		failed_to_init = true;
		return err;
	}
	return OK;
}
