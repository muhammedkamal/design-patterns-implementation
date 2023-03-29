<?php

interface Listener {
    public function handleEvent($data);
}

class EventDispatcher {
    private $listeners = [];

    public function addListener(Listener $listener) {
        $this->listeners[] = $listener;
    }

    public function dispatchEvent($data) {
        foreach ($this->listeners as $listener) {
            $listener->handleEvent($data);
        }
    }
}

class LogListener implements Listener {
    public function handleEvent($data) {
        echo "Logging event: $data\n";
    }
}

class EmailListener implements Listener {
    public function handleEvent($data) {
        echo "Sending email notification: $data\n";
    }
}

$dispatcher = new EventDispatcher();
$dispatcher->addListener(new LogListener());
$dispatcher->addListener(new EmailListener());

$dispatcher->dispatchEvent("User logged in");