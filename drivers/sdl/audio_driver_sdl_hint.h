/**************************************************************************/
/*  audio_driver_sdl_hint.h                                               */
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

#pragma once

#include "servers/audio_server.h"

class AudioDriverSDLHint : public AudioDriver {
	friend class AudioDriverSDL;

	virtual const char *get_driver_name() const = 0;

public:
	static const LocalVector<AudioDriverSDLHint *> audio_driver_hints;

	virtual Error init() override;
	virtual void start() override;
	virtual int get_mix_rate() const override;
	virtual SpeakerMode get_speaker_mode() const override;
	virtual float get_latency() override;

	virtual void lock() override;
	virtual void unlock() override;
	virtual void finish() override;

	virtual PackedStringArray get_output_device_list() override;
	virtual String get_output_device() override;
	virtual void set_output_device(const String &p_name) override;

	virtual Error input_start() override;
	virtual Error input_stop() override;

	virtual PackedStringArray get_input_device_list() override;
	virtual String get_input_device() override;
	virtual void set_input_device(const String &p_name) override;
};

class AudioDriverSDLNone : public AudioDriverSDLHint {
	static bool failed_to_init;

	virtual const char *get_driver_name() const {
		return nullptr;
	}

public:
	virtual const char *get_name() const;

	virtual Error init() override;

	static bool is_failed_to_init() {
		return failed_to_init;
	}
};

class AudioDriverSDLALSA : public AudioDriverSDLHint {
	virtual const char *get_driver_name() const {
		return "alsa";
	}

public:
	virtual const char *get_name() const {
		return "SDL (ALSA)";
	}
};

class AudioDriverSDLCoreAudio : public AudioDriverSDLHint {
	virtual const char *get_driver_name() const {
		return "coreaudio";
	}

public:
	virtual const char *get_name() const {
		return "SDL (CoreAudio)";
	}
};

class AudioDriverSDLPulseAudio : public AudioDriverSDLHint {
	virtual const char *get_driver_name() const {
		return "pulseaudio";
	}

public:
	virtual const char *get_name() const {
		return "SDL (PulseAudio)";
	}
};

class AudioDriverSDLWASAPI : public AudioDriverSDLHint {
	virtual const char *get_driver_name() const {
		return "wasapi";
	}

public:
	virtual const char *get_name() const {
		return "SDL (WASAPI)";
	}
};
