$(document).ready(function() {
    $(window).on("load", function() {
        $(".preloader").fadeOut("slow");
    });
    setTimeout(function() {
        $('.preloader').fadeOut('slow', function() {});
    }, 500);
    $('#table_content').mousewheel(function(e, delta) {
        this.scrollLeft -= (delta * 230);
        e.preventDefault();
    });
    $('#slide_left').click(function() {
        $('#table_content').animate({
            scrollLeft: '+=231'
        }, 600);
    });
    $('[data-fancybox]').fancybox();
    $('body').mouseup(function(e) {
        var sort = $(".sort_select");
        if (!sort.is(e.target) && sort.has(e.target).length === 0) {
            $(".sort_options").fadeOut("slow");
        }
    });
    $(".sort_option").click(function() {
        customOptionsBlock = $(this).parent('.sort_select').find(".sort_options");
        if (customOptionsBlock.is(":hidden")) {
            customOptionsBlock.fadeIn("slow");
        } else {
            customOptionsBlock.fadeOut("slow");
        }
    });
    $(".sort_options li").click(function() {
        choosenValue = $(this).attr("data-custom");
        $(this).parents('.sort_select').find(".sort_option .text").text($(this).text());
        $(this).parents('.sort_select').find(".sort_option").attr("data-custom", choosenValue);
        $(this).parents('.sort_select').find(".sort_options").fadeOut("slow");
    });
    $('.measure').click(function(event) {
        event.preventDefault();
        var title = $(this).data('name');
        if (title) {
            $('#modal .title span').text(title);
        } else {
            $('#modal .title span').text("");
        }
        $('#overlay').addClass('active').fadeIn(400, function() {
            $('.modal#modal').css('display', 'block').animate({
                opacity: 1
            });
        });
    });
    $('.comment_open').click(function(event) {
        event.preventDefault();
        $('#overlay').addClass('active').fadeIn(400, function() {
            $('.modal#modal_comment').css('display', 'block').animate({
                opacity: 1
            });
        });
    });
    $('.change_name').click(function(event) {
        event.preventDefault();
        $('#overlay').addClass('active').fadeIn(400, function() {
            $('.modal#modal_change_name').css('display', 'block').animate({
                opacity: 1
            });
        });
    });
    $('#overlay').click(function() {
        $('.modal').animate({
            opacity: 0
        }, function() {
            $(this).css('display', 'none');
            $('#overlay').removeClass('active').fadeOut(400);
        });
    });
    $('.modal .close_modal').click(function() {
        $('.modal').animate({
            opacity: 0
        }, function() {
            $(this).css('display', 'none');
            $('#overlay').removeClass('active').fadeOut(400);
        });
    });
    $(function($) {
        $(".table_box .left_column").each(function() {
            var length = $(this).find('.row').length;
            console.log(length);
            for (var i = 1; i < length + 1; i++) {
                var max_col_height = 0;
                $('[data-row="row_' + i + '"]').each(function() {
                    if ($(this).height() > max_col_height) {
                        max_col_height = $(this).height();
                    }
                });
                $('[data-row="row_' + i + '"]').height(max_col_height);
            }
        });
    });
});