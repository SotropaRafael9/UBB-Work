// wait until the document is loaded and ready
$(document).ready(function () {
    // get the width of the current window
    const windowWidth = $(window).width();

    // set the initial desktop to be shown as the first desktop
    let currentDesktop = $("#desktop1");
    // show the initial desktop
    currentDesktop.show();

    $(".desktop").click(function () {
        // animate the current desktop to slide to the left of the window
        currentDesktop.animate({
            left: -windowWidth,  // set the left position of the desktop to the negative width of the window
            opacity: 0          // set the opacity to 0, progressively making the disappearing desktop transparent
        }, 1000, function () {    // duration of the animation is 1 sec
            // when the animation is complete, move the current desktop out of the view and reset its position and opacity
            currentDesktop.css({left: "100%", opacity: 1});
            // get the next desktop
            var nextDesktop = currentDesktop.next(".desktop");
            // if there is no next desktop, set it to be the first desktop
            if (nextDesktop.length === 0) {
                nextDesktop = $(".desktop").first();
            }
            // move the next desktop to the right of the window and set its opacity to 0, making it transparent
            nextDesktop.css({left: windowWidth, opacity: 0});
            // show the next desktop
            nextDesktop.show();
            // animate the desktop to slide in from the right of the window and fade in
            nextDesktop.animate({left: "0%", opacity: 1}, 1000);
            // set the next desktop as the new current desktop
            currentDesktop = nextDesktop;
        });
    });
});